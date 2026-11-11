#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N=5e5+10;
struct Edge
{
	ll u,w;
};
vector<Edge> g[N*20];
ll w[N],ans[N],d[N*20];
bool vis[N*20];
pair<ll,pair<ll,ll>> q1[N];

void dij(ll s)
{
	priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > q;
	q.push(make_pair(0,s));
	vis[s]=false;
	d[s]=0;
	while(q.size()>0)
	{
		pair<ll,ll> cur=q.top();
		q.pop();
		if(vis[cur.second]) continue;
		vis[cur.second]=true;
		for(auto i:g[cur.second])
		{
			if(!vis[i.u]&&d[i.u]>=d[cur.second]+i.w) d[i.u]=d[cur.second]+i.w,q.push(make_pair(d[cur.second]+i.w,i.u));
		}
	}
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	ll c,n,m,d1,q,cnt=0;
	cin>>c>>n>>m>>d1>>q;
	for(ll i=1;i<=m;i++) cin>>w[i];
	for(ll i=1;i<=n;i++)
	{
		ll k;
		cin>>k;
		ll last=-1;
		for(ll j=1;j<=k;j++)
		{
			ll u,w1;
			cin>>u>>w1;
			cnt++;
			g[u].push_back((Edge){m+cnt,w1});
			g[m+cnt].push_back((Edge){u,w1});
			if(last==-1) {last=m+cnt;continue;}
			g[last].push_back((Edge){m+cnt,0});
			g[m+cnt].push_back((Edge){last,0});
		}
	}
	
	for(ll i=1;i<=q;i++)
	{
		ll l,r;
		cin>>l>>r;
		q1[i].first=l,q1[i].second.first=r,q1[i].second.second=i;
		if(q1[i].first>q1[i].second.first) swap(q1[i].first,q1[i].second.first);
	}
	sort(q1+1,q1+q+1);
	for(ll i=1;i<=q;i++)
	{
		for(ll j=1;j<=m+cnt;j++) vis[j]=0,d[j]=1e18+10;
		dij(q1[i].first);
		ans[q1[i].second.second]=d[q1[i].second.first]+w[q1[i].first]+w[q1[i].second.first];
		i++;
		for(;i<=q;i++)
		{
			if(q1[i].first==q1[i-1].first) ans[q1[i].second.second]=d[q1[i].second.first]+w[q1[i].first]+w[q1[i].second.first];
			else break;
		}
		i--;
	}
	for(ll i=1;i<=q;i++) cout<<ans[i]<<"\n";
	return 0;
}
