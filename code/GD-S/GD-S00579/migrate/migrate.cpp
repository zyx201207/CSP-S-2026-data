#include<bits/stdc++.h>
using namespace std;
// struct st
// {
// 	int id,v;
// 	bool operator <(const st &x)const
// 	{
// 		return v>x.v;
// 	}
// };
// int cnt;
// void dfs(int u,int v,int w,int cst)
// {
// 	if()
// }
int main()
{
// 	typedef pair<int,int> pii;
// #define fi first 
// #define sc second
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		long long n,d;
		cin>>n>>d;
		// vector<vector<bool>>eg(n+1,vector<bool>(n+1));
		vector<long long>x(n+1);
		// for(int i=1;i<=n;i++)
			// cin>>x[i];
		vector<vector<long long>>dis(n+1,vector<long long>(n+1,(LLONG_MAX>>2)));
		vector<vector<long long>>dis2(n+1,vector<long long>(n+1,(LLONG_MAX>>2)));
		for(int i=1;i<=n;i++)
			dis[i][i]=0;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			for(int j=i-1;j>=1;j--)
			if(x[i]-x[j]<=d)
				dis[j][i]=dis[i][j]=1;
			else break;
		}
		// for(int i=1;i<=n;i++)
		// 	for(int j=i+1;j<=n;j++)
		// 		dfs(i,j,i,0)
		for(int i=1;i<=n;i++)
			for(int u=1;u<=n;u++)
				for(int v=1;v<=n;v++)
				{
					if(i==u||i==v||v==u)continue;
					// if(i==2&&u==1&&v==4)cout<<"ll";
					if(dis[u][v]>=dis[u][i]+dis[i][v])
					{
						dis2[u][v]=dis[u][v];
						dis[u][v]=dis[u][i]+dis[i][v];
						// cout<<"dis";
					}
					// else if(dis2[u][v]>dis[u][i]+dis[i][v])
					// 	dis2[u][v]=dis[u][i]+dis[i][v];
				}
		long long ans=0;
		for(int u=1;u<=n;u++)
		{
			for(int v=u+1;v<=n;v++)
			{
				// cout<<dis[u][v];
				if(dis[u][v]==dis2[u][v]&&dis[u][v]!=1e8&&u!=v)
					ans++;
			}
			// cout<<'\n';
		}
		// for(int u=1;u<=n;u++)
		// {
		// 	for(int v=u+1;v<=n;v++)
		// 	{
		// 		cout<<dis2[u][v]<<' ';
		// 	}
		// 	cout<<'\n';
		// }
		cout<<ans<<'\n';
	}

	return 0;
}
