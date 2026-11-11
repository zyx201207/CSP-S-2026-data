#include <bits/stdc++.h>
#include <cstring>
using namespace std;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	cin >> n >> m;
	int ans[m] = {0},card[n];
	for(int i = 0;i < n;i++)
	{
		cin >> card[i];
	}
	
	for(int game = 1;game <= n;game++)
	{
		int tab[n] = {0},t = 0;
		for(int c = (game - 1);c < n;c++,t++)
		{
			tab[t] = card[c];
			for(int i = (t - 1);i >= 0;i--)
			{
				if(tab[i] == tab[t])
				{
					for(int del = (i + 1);del <= t;del++)
					{
						tab[del] = 0;
					}
					t = i;
					break;
				}
			}
		}
		for(int i = 0;i <= t;i++)
		{
			ans[tab[i] - 1]++;
		}
	}
	
	for(int i = 0;i < m;i++)
	{
		cout << ans[i] << " ";
	}
	
	return 0;
}
