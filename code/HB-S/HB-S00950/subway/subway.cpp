#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[505],dis[505][505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>q;
	for(int i = 1;i <= n;i++)
	{
		cin>>w[i];
		dis[i-1][i] = w[i]+w[i-1];
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = i+1;j <= n;j++)
		{
			for(int k = i;k <= j;k++)
			{
				dis[i][j] = max(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i = 1;i <= q;i++)
	{
		int xi,yi;
		cin>>xi>>yi;
		cout<<dis[xi][yi]<<endl;
	}
	return 0;
}
//☠RP++
