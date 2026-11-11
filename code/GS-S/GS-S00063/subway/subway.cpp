#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int a[1145][1145],t[1145][1145],k[11451];
int b[1145],e[1145];
int w[114514];
int ans[1145];
int temp[1145],temp_num;

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >>c >>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++)
	{
		cin >>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin >> k[i];
		for(int j=1;j<=k[i]*2;j++)
		{
			cin >>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin >>b[i]>>e[i];
	}

	
	
	for(int h=1;h<=q;h++)//h×é²âÊÔµã 
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=k[i];j++)
			{
				if(b[h]==a[i][j])
				{
					for(int l=j;l<=k[i];l++)
					{
						if(e[h]==a[i][l])
						{
							temp_num++;
							temp[h]=w[b[h]]+w[e[h]]+t[i][b[h]]+t[i][e[h]];
						}
					}
				}
			}
		}
		for(int i=1;i<temp_num;i++)
		{
			ans[h]=min(temp[i],temp[i+1]);
		}
	}
	for(int i=1;i<=q;i++)
	{
		cout << ans[i];
	}
	return 0;
}
