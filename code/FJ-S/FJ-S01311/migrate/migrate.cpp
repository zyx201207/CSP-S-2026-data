#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pa pair<ll,ll>
#define fi first
#define se second
ll c,T;
ll n,d,x[2000005];
vector<ll> e[2000005];
queue<pa > q;
ll vis[2000005];
ll ans;
ll minn[2000005];
ll lj[2000005];
void bfs(ll fa)
{
	q.push(make_pair(1,0));
	vis[fa]=1;
	while (q.size())
	{
		ll u=q.front().fi,step=q.front().se;
		q.pop();
		for (ll i=0;i<e[u].size();i++)
		{
			ll v=e[u][i];
//			cout<<"fa:"<<fa<<" u:"<<u<<" v:"<<v<<" vis v:"<<vis[v]<<endl;
			if (vis[v]==step+1)
				lj[v]++;
			else
				if (vis[v]>step+1)
					vis[v]=step+1,lj[v]=1;
			q.push(make_pair(v,step+1));
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while (T--)
	{
		ans=0;
		scanf("%lld%lld",&n,&d);
		for (ll i=1;i<=n;i++)
			scanf("%lld",&x[i]);
		for (ll i=1;i<=n;i++)
			for (ll j=i+1;j<=n;j++)
				if (x[j]-x[i]<=d)
					e[i].push_back(j);
				else
					break;
		for (ll i=1;i<=n-2;i++)
		{
			memset(vis,0x3f3f3f3f,sizeof(vis));
			memset(lj,1,sizeof(lj));
			bfs(i);
			for (ll j=i+1;j<=n;j++)
				if (lj[j]==2)
					ans++;
		}
		printf("%lld\n",ans);
		for (ll i=1;i<=n;i++)
			e[i].clear();
	}
	return 0;
	}

