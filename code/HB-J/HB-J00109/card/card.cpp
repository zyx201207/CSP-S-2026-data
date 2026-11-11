#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
int n,m;
int ansnum[200005];
int str[200005],ans[200005];
int anssize;
bool pp = true;
int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for (int i = 0;i < n; i++)
    {
		cin >> str[i];
		if(i!=0)
		{
			if(str[i-1] > str[i]) pp = false;
		}
	}
	if(pp)
	{
		for (int i = 0;i < n; i++)
		{
			if(str[i] != str[i+1])
			{
				ansnum[str[i] - 1] = i + 1;
			}
		}
			for (int i = 0;i < m; i++)
	{

		cout << ansnum[i] << ' ';

	}
	return 0;
	}
	for (int i = 0;i < n; i++)
    {
		anssize = 0;
		for (int j = i;j < n; j++)
		{
			bool p = false;
			for(int k = 0;k < anssize;k++)
			{
				if(ans[k] == str[j])
				{
					anssize = k+1;
					p = true;
					break;
				}
			}
			if(p) continue;
			ans[anssize++] = str[j];
		}
		for (int j = 0;j < m; j++)
		{

			for(int k = 0;k < anssize;k++)
			{
				if(ans[k] == j + 1)
				{
					ansnum[j]++;
					break;
				}
			}
		}

	}
	for (int i = 0;i < m; i++)
	{

		cout << ansnum[i] << ' ';

	}
    return 0;
}
