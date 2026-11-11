#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll c,n,m,d,r,w[500010],dist[500010][2001],tim;
map<pair<ll,ll>,ll>mp;
struct str
{
	ll x;//x 号线/x 号站厅 
	ll t;
};
vector<str>zt[500010];
vector<str>xl[500010];
struct cla
{
	ll x;
	ll s;
	ll op;//1:站台上  2:线路上 
};

void bfs(ll su)
{
	tim++;
	dist[su][tim]=0;
	queue<cla>q;
	q.push({su,0,1});
	while(!q.empty())
	{
		cla k=q.front();
		q.pop();
		if(k.op==1)
		{
			for(int i=0;i<zt[k.x].size();i++)
			{
				q.push({zt[k.x][i].x,k.s+zt[k.x][i].t,2});
			}
		}
		else
		{
			for(int i=0;i<xl[k.x].size();i++)
			{
				if(k.s+xl[k.x][i].t<dist[xl[k.x][i].x][tim])
				{
					dist[xl[k.x][i].x][tim]=k.s+xl[k.x][i].t;
					q.push({xl[k.x][i].x,k.s+xl[k.x][i].t,1});
				}
			}
		}
	}
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin>>c>>n>>m>>d>>r;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		ll k;
		cin>>k;
		for(ll j=1;j<=k;j++)
		{
			ll a,t;
			cin>>a>>t;
			zt[a].push_back({i,t});
			xl[i].push_back({a,t});
		}
	}
	for(int i=1;i<=r;i++)
	{
		ll s,e;
		cin>>s>>e;
		if(mp[{s,e}])
		{
			cout<<mp[{s,e}]<<"\n";
			continue;
		}
		bfs(s);
		mp[{s,e}]=dist[e][tim]+w[s]+w[e];
		cout<<dist[e]+w[s]+w[e]<<"\n";
	}
	return 0;
}
