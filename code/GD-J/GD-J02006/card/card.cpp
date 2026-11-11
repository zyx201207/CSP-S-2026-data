#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.ans","w",stdout);
	int n,m,card[20005];
	int table[20005] = {};
	int k[20005] = {};
	cin >> n >> m;
	int play = n;
	for(int i=1;i<=n;i++)
	{
		cin >> card[i];
	}
	int i=n;
	while(play>=1)
	{
		if(i!=0)
		{
			for(int j=n;j>=i;j--)
			{
				if(card[i]==table[j])
				{
					for(int x=n;x>=i;x--)
					{
						table[x] = 0;
					}
					table[n]=card[i];
				}
				else
				{
					table[i] = card[i];
				}
			}
		}
		else
		{
			for(int u=1;u<=m;u++)
			{
				for(int x=n;x>=1;x--)
				{
					if(u == table[x])
					{
						k[u]++;
					}
					break;
				}
			}
			for(int e=1;e<=n;e++)
			{
				table[e]=0;
			}
			i=n+1;
		}
		play--;
		i--;
	}
	for(int z=1;z<=m;z++)
	{
		cout << k[z] << " ";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
