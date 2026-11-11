#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 2000005
int t,n,d,a[N];
vector<int>g[N];
int dis[N],cnt[N];
queue<int>q;
void bfs(int s)
{
	for(int i=s;i<=n;i++) dis[i]=1e9,cnt[i]=0;
	dis[s]=0;
	cnt[s]=1;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=0;i<g[u].size();i++)
		{
			int v=g[u][i];
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				cnt[v]=cnt[u];
				q.push(v);
			}else if(dis[v]==dis[u]+1) cnt[v]+=cnt[u];
		}
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin>>T>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(T==11||T==12)
		{
			int j=1;
			while(a[j]-a[1]<=d) j++;j--;
			if(j<=2) cout<<0<<'\n';
			else cout<<max(0ll,n-(j-1<<1)+1)<<'\n';
			continue;
		}
		if(T==13||T==14)
		{
			cout<<0<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]>d) continue;
				g[i].push_back(j);
			}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			bfs(i);
			for(int j=i+1;j<=n;j++)
				if(cnt[j]==2) ans++;
		}
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++) g[i].clear();
	}
	return 0;
}
/*
0 1
10 22
0 7 14 21 28 35 42 49 56 63
*/
