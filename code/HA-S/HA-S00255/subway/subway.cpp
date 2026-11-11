#include<bits/stdc++.h>
#include<windows.h>
#define ll long long
using namespace std;
ll w[500010],dist[500010];
struct hh{
	ll d;ll t;
};
struct road{
	ll to;ll t;
};
struct kk{
	ll x;ll t;
};
vector<vector<road> >r(500010);
vector<vector<hh> >cun(510);
vector<vector<kk> >dcun(500010);
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>di;
const ll L=100000001000;

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)
	cin>>w[i];
	for(ll i=1;i<=n;i++)
	{
		ll k;cin>>k;
		for(ll o=1;o<=k;o++)
		{
			ll a,jt;cin>>a>>jt;
			cun[i].push_back(hh{a,jt});//d,t
			if(k!=1)
			dcun[a].push_back(kk{i,jt});
			if(k==1)
			break;
			for(ll j=0;j<cun[a].size();j++)
			{
				if(cun[i][j].d==a)
				continue;
				r[a].push_back(road{cun[i][j].d,0});
				r[cun[i][j].d].push_back(road{a,0});
			}
			for(ll j=0;j<dcun[a].size();j++)
			{
				if(dcun[a][j].x==i)
				continue;
				r[a].push_back(road{cun[dcun[i][j].x][0].d,dcun[a][j].t+dcun[a][i].t});
				r[cun[dcun[i][j].x][0].d].push_back(road{a,dcun[a][j].t+dcun[a][i].t});
			}
		}
	}
	while(q--){
		ll x,y;cin>>x>>y;
		for(ll i=1;i<=m;i++)
		{
			if(i!=x)
			dist[i]=0;
			else
			dist[i]=L;
		}
		ll l=500009;
		r[l].clear();
		for(ll i=0;i<dcun[x].size();i++)
		{
			r[l].push_back(road{cun[dcun[x][i].x][0].d,dcun[x][i].t});
		}
		for(ll i=0;i<dcun[y].size();i++)
		{
			r[cun[dcun[y][i].x][0].d].push_back(road{0,dcun[y][i].t});
		}
		dist[l]=0;
		di.push({0,l});
		while(!di.empty())
		{
			pair<ll,ll> j=di.top();
			di.pop();
			if(j.first>dist[j.second])
			continue;
			for(ll i=0;i<r[j.second].size();i++)
			{
				if(dist[r[j.second][i].to]>j.first+r[j.second][i].t);
				{
					dist[r[j.second][i].to]=j.first+r[j.second][i].t;
					di.push({dist[r[j.second][i].to],r[j.second][i].to});
				}
			}
			
		}
		for(ll i=1;i<=dcun[y].size();i++)
		{
			r[cun[dcun[y][i].x][0].d].pop_back();
		}
		cout<<dist[y]+w[x]+w[y]<<'\n';
	}
	return 0;
}
