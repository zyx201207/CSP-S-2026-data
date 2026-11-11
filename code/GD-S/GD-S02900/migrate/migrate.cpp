#include<bits/stdc++.h>
#define int long long
#define pa pair<int,int>
#define fre freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout)
using namespace std;
const int MAXN=3e6+34,inf=1e18;
struct asd{
	vector<int> to;
}g[MAXN];
int c,n,t,d,x[MAXN],dis[MAXN],cnt[MAXN],ans;
void bfs(const int s)
{
	for(int i=1;i<=n;i++) dis[i]=inf,cnt[i]=0;
	priority_queue<pa,vector<pa>,greater<pa> > q;dis[s]=0,cnt[s]=1,q.push({0,s});
	while(!q.empty())
	{
		const int u=q.top().second,len=q.top().first;q.pop();
		if(len>dis[u]) continue;
		for(int i=0;i<g[u].to.size();i++)
			if(dis[g[u].to[i]]>len+1) dis[g[u].to[i]]=len+1,cnt[g[u].to[i]]=cnt[u],q.push({len+1,g[u].to[i]});
			else if(dis[g[u].to[i]]==len+1) cnt[g[u].to[i]]+=cnt[u];
	}
}
signed main()
{
	fre;
	for(cin>>c>>t;t;t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++) for(int j=i+1;j<=n&&x[j]-x[i]<=d;j++) g[i].to.push_back(j),g[j].to.push_back(i);
		for(int i=1;i<=n;i++)
		{
			bfs(i);
			for(int j=i+1;j<=n;j++) ans+=(cnt[j]==2);
		}
		for(int i=1;i<=n;i++) g[i].to.clear();
		cout<<ans<<endl,ans=0;
	}
	return 0;
}
