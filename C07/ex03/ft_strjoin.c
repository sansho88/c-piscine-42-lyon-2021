/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriffit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 21:29:06 by tgriffit          #+#    #+#             */
/*   Updated: 2021/08/25 14:55:22 by tgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_tabslen(char	**strs, int size)
{
	int	j;
	int	count;
	int	i;

	j = 0;
	i = 0;
	count = 0;
	while (i < size)
	{
		while (strs[i][j])
		{
			count++;
			j++;
		}
		j = 0;
		i++;
	}
	return (count);
}

void	ft_strcat(char *s1, char const *s2)
{
	int	size1;
	int	size2;

	size1 = 0;
	size2 = 0;
	while (s1[size1])
		size1++;
	while (s2[size2])
	{
		s1[size1 + size2] = s2[size2];
		size2++;
	}
	s1[size1 + size2] = '\0';
}

/* @sizestrs = total of chars in all strs, useful for malloc */
char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		i;

	i = 0;
	if (size <= 0)
	{
		result = malloc(1);
		if (!result)
			return (0);
		result = "\0";
		return (result);
	}
	result = malloc(sizeof(char) * (ft_tabslen(strs, size)
				+ (ft_strlen(sep) * (size - 1) + 100)));
	if (!result)
		return (0);
	result[0] = '\0';
	while (i < size)
	{
		ft_strcat(result, strs[i]);
		if (i < size - 1)
			ft_strcat(result, sep);
		i++;
	}
	return (result);
}
