#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define db double
#define ldb long double
#define ls(rt) (rt<<1)
#define rs(rt) (rt<<1|1)
#define pii pair<int,int>

const int N=500;
const int M=1e5;
const ll inf=1e18;

int c,n,m,d,q;
vector<pii>edgen[N+5];
vector<pii>edgem[M+5];
int pay[M+5];
ll ne[N+5][M+5];
ll visn[N+5];
ll vism[M+5];

bool operator >(pair<pii,ll>a,pair<pii,ll>b){return a.second<b.second;}
bool operator <(pair<pii,ll>a,pair<pii,ll>b){return a.second>b.second;}

void solve()
{
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++)cin>>pay[i];
	for(int i = 1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int u,w;
			cin>>u>>w;
			edgen[i].push_back({u,w});
			edgem[u].push_back({i,w});
		}
	}
	for(int rt = 1;rt<=n;rt++)
	{
		for(int i = 1;i<=n;i++)visn[i]=inf;
		for(int i = 1;i<=m;i++)vism[i]=inf;
		priority_queue<pair<pii,ll>,vector<pair<pii,ll>>>pq;
		pq.push({{0,rt},0});
		visn[rt]=0;
		while(!pq.empty())
		{
			auto p=pq.top();
			pq.pop();
			bool f=p.first.first;
			int id=p.first.second;
			ll now=p.second;
			if(f)
			{
				if(vism[id]<now)continue;
				for(auto pp:edgem[id])
				{
					int to=pp.first;
					ll w=pp.second;
					if(visn[to]>w+now)
					{
						pq.push({{0,to},w+now});
						visn[to]=w+now;
					}
				}
			}
			else
			{
				if(visn[id]<now)continue;
				for(auto pp:edgen[id])
				{
					int to = pp.first;
					ll w=pp.second;
					if(vism[to]>w+now)
					{
						pq.push({{1,to},w+now});
						vism[to]=w+now;
					}
				}
			}
		}
		for(int i = 1;i<=m;i++)ne[rt][i]=vism[i];
	}
	while(q--)
	{
		int u,v;
		cin>>u>>v;
		ll ans=inf;
		for(int i = 1;i<=n;i++)ans=min(ans,ne[i][u]+ne[i][v]);
		ans+=pay[u]+pay[v];
		cout<<ans<<endl;
	}
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
//	cout<<t;
	while(t--){solve();}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
