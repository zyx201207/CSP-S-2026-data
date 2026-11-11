//subway
#include <bits/stdc++.h>
#define ll long long 
#define ls (x<<1)
#define rs (ls+1)
#define mod (ll)(1e9+7)
#define pii pair<ll,int>
using namespace std;
const int N=5e3+505;
const int Q=1e5+505;
int c,n,m,d,q;
struct AC
{
	ll v,w,nx;
}bian[N];
queue <pii> ques[N];
ll cnt;
ll w[N],ans[Q];
ll fir[N];
void add(int u,int v,ll w)
{
	cnt++;
	bian[cnt].v=v;
	bian[cnt].w=w;
	bian[cnt].nx=fir[u];
	fir[u]=cnt;
}
ll dis[N];
bool bk[N];
void dij(int s)
{
	memset(bk,0,sizeof bk);
	memset(dis,0x3f,sizeof dis);
	priority_queue <pii> q;
	dis[s]=0;
	q.push({0,s});
	while(!q.empty())
	{
		ll u=q.top().second;
		q.pop();
		if(bk[u]==1)continue;
		bk[u]=1;
		for(ll i=fir[u];i!=0;i=bian[i].nx)
		{
			ll v=bian[i].v,w=bian[i].w;
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				q.push({-dis[v],v});
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)cin>>w[i];
	for(ll i=1;i<=n;i++)
	{
		ll k;
		cin>>k;
		while(k--)
		{
			ll a,t;
			cin>>a>>t;
			add(m+i,a,t);
			add(a,m+i,t);
		}
	}
	for(ll i=1;i<=q;i++)
	{
		ll x,y;
		cin>>x>>y;
		if(x>y)swap(x,y);
		ques[x].push({y,i});
	}
	for(ll i=1;i<=m;i++)
	{
		if(ques[i].empty())continue;
		dij(i);
		while(!ques[i].empty())
		{
			pii nw=ques[i].front();
			ques[i].pop();
			ans[nw.second]=dis[nw.first]+w[i]+w[nw.first];
		}
	}
	for(ll i=1;i<=q;i++)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}
