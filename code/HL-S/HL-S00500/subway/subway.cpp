#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 500005;
int c,n,m,d,r,w[N],a[N],t[N],dis[N];
bool vis[N];
vector <pii> vec[N];
inline int dij(int x,int y)
{
	for(int i=1;i<=m;i++) dis[i] = LLONG_MAX,vis[i] = 0;
	dis[x] = 0;
	priority_queue <pii,vector<pii>,greater<pii>> q;
	q.push({0,x});
	while(q.size())
	{
		int f = q.top().second;
		q.pop();
		if(vis[f]) continue;
		vis[f] = 1;
		for(int i=0;i<vec[f].size();i++)
		{
			if(dis[vec[f][i].first] > dis[f] + vec[f][i].second)
			{
				dis[vec[f][i].first] = dis[f] + vec[f][i].second;
				q.push({dis[vec[f][i].first],vec[f][i].first});
			}
		}
	}
	return dis[y];
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>r;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int p;
		cin>>p;
		for(int j=1;j<=p;j++) cin>>a[j]>>t[j];
		for(int j=1;j<=p;j++)
		{
			for(int k=j+1;k<=p;k++)
			{
				vec[a[j]].push_back({a[k],t[j]+t[k]});
				vec[a[k]].push_back({a[j],t[j]+t[k]});
			}
		}
	}
	while(r--)
	{
		int x,y;
		cin>>x>>y;
		cout<<dij(x,y)+w[x]+w[y]<<"\n";
	}
	return 0;
}