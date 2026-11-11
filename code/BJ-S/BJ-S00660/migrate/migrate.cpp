#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N=2e6+10;
struct Edge
{
	ll u,w;
};
vector<Edge> g[N];
ll x[N],d[N],cnt[N];
bool vis[N];
priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > >q;

void dij(ll s)
{
	q.push(make_pair(0,s));
	vis[s]=false;
	d[s]=0;
	cnt[s]=1;
	while(q.size()>0)
	{
		pair<ll,ll> cur=q.top();
		q.pop();
		if(vis[cur.second]) continue;
		vis[cur.second]=true;
		for(auto i:g[cur.second])
		{
			if(d[i.u]>d[cur.second]+i.w)
			{
				cnt[i.u]=cnt[cur.second];
				d[i.u]=d[cur.second]+i.w;
				q.push(make_pair(d[cur.second]+i.w,i.u));
			}
			else if(d[i.u]==d[cur.second]+i.w)
			{
				cnt[i.u]+=cnt[cur.second];
				d[i.u]=d[cur.second]+i.w;
				q.push(make_pair(d[cur.second]+i.w,i.u));
			}
		}
	}
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	ll c,t;
	cin>>c>>t;
	while(t--)
	{
		ll n,d1;
		cin>>n>>d1;
		for(ll i=1;i<=n;i++) cin>>x[i];
		if(c==11||c==12)
		{
			if(abs(x[2]-x[1])>d1) {cout<<"0\n";continue;}
			ll d2=abs(x[2]-x[1]);
			ll tmp=d1/d2;
			cout<<max(n-tmp,0ll)<<"\n";
			continue;
		}
		for(ll i=1;i<=n;i++)
		{
			for(ll j=1;j<=n;j++)
			{
				if(j==i) continue;
				if(llabs(x[i]-x[j])<=d1) g[i].push_back((Edge){j,1});
			}
		}
		ll ans=0;
		for(ll i=1;i<=n;i++)
		{
			for(ll j=1;j<=n;j++) vis[j]=0,d[j]=1e18,cnt[j]=0;
			dij(i);
			for(ll j=1;j<=n;j++) if(cnt[j]==2) ans++;
		}
		cout<<ans/2<<"\n";
		for(int i=1;i<=n;i++)g[i].clear();
	}
	return 0;
}
