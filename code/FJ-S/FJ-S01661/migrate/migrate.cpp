#include<bits/stdc++.h>
using namespace std;
constexpr int N=2e6+10;
using ll = long long;
int c,T,n;
ll d;
ll x[N],f[N];
int dis[N];
queue <int> q;
inline void bfs(int s)
{
	for(int i=1;i<=n;i++)
		dis[i]=0x3f3f3f3f,f[i]=0;
	q.push(s); dis[s]=0; f[s]=1;
	while(!q.empty())
	{
		int k=q.front(); q.pop();
		for(int i=k;i>=1;i--)
		{
			if(x[k]-x[i]>d) break;
			if(dis[i]==dis[k]+1) f[i]+=f[k];
			if(dis[i]>dis[k]+1)
			{
				dis[i]=dis[k]+1;
				f[i]=f[k];
				q.push(i);
			}
		 } 
		for(int i=k;i<=n;i++)
		{
			if(x[i]-x[k]>d) break;
			if(dis[i]==dis[k]+1) f[i]+=f[k];
			if(dis[i]>dis[k]+1)
			{
				dis[i]=dis[k]+1;
				f[i]=f[k];
				q.push(i);
			}
		}
	}
}
inline void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>x[i];
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		bfs(i);
		for(int j=i;j<=n;j++)
			if(f[j]==2) ans++;
	}
	printf("%lld\n",ans);
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--)
		solve();
	return 0;
}
