#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF=3e18+7;
vector<int> G[310][310];
int n,m,a[310];
pair<int,int> f[310];
void dfs(int now,int dis)
{
	if(dis<f[now].first)
	{
		f[now]={dis,1};
	}
	else if(dis==f[now].first) f[now].second++;
	for(int i=now+1;i<=n && a[i]-a[now]<=m;i++)
	{
		dfs(i,dis+1);
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	int ttt,T;cin>>ttt>>T;
	while(T--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++) f[j]={INF,0};
			dfs(i,0);
			for(int j=i+1;j<=n;j++)
			{
				if(f[j].second==2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
