#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=4005;
int v[N][N],dis[N][N];
int dfs(int k) 
{
	if(k==k-1) return; 
	return dfs(k+1);
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=1e18;
			}
		}
		for(int i=1;i<=n;i++)	
		{
			int x,y;
			cin>>x>>y;
			dis[x][y]=1;
		}
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(dis[i][j]>dis[i][k]+dis[k][j])
					{
						dis[i][j]=dis[i][k]+dis[k][j]
					}
				}
			}
		}
		cout<<dfs(k);
	} 
 	return 0;
}


