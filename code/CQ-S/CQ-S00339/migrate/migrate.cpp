#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e6+5;
ll x[N],sum[N],dis[N],cnt[N],n,d;
struct node
{
	ll v,w;
};
struct Node
{
	ll u,w;
	friend bool operator >(const Node &x,const Node &y){return x.w>y.w;}
};
vector<node>e[N];
ll bfs(ll qx)
{
	for (ll i=1;i<=n;i++) dis[i]=1e18,cnt[i]=0;
	priority_queue<Node,vector<Node>,greater<Node> >q;
	dis[qx]=0;q.push({qx,0});
	while (q.size())
	{
		Node _=q.top();q.pop();
		ll u=_.u,w=_.w;
		if (w==dis[u]) cnt[u]++;
		for (auto [v,w]:e[u])
		{
			if (dis[u]+w<=dis[v]){dis[v]=dis[u]+w;q.push({v,dis[v]});}
		}
	}
	ll ans=0;
	for (ll i=1;i<=n;i++)
	{
		if (i==qx) continue;
		if (cnt[i]==2) ans++;
	}
	return ans;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll _,t; cin >>_>>t;
	while (t--)
	{
		cin >>n>>d;
		for (ll i=1;i<=n;i++) 
		{
			cin >>x[i];
			if(i>1) sum[i]=sum[i-1]+(x[i]-x[i-1]);
			e[i].clear();
		}
		for (ll i=1;i<=n;i++)
		{
			for (ll j=i+1;j<=n;j++)
			{
				if (sum[j]-sum[i]<=d) e[i].push_back({j,1});
				else break; 
			}
		}
		ll ans=0;
		for (ll i=1;i<=n;i++) ans+=bfs(i);
		cout <<ans<<'\n';
	}
	return 0;
 }
/*16:31 40·Ö 
°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡°¡ÈýµÀÍ¼ÂÛ 
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
kao kao kao kao kao kao kao
na jiu hao hoa dao ge bie ba
*/
