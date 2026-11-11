#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q,w[500005],x,y,dis[1005][1005],vis[1000006];
const ll inf=1e18;
vector<pair<int,ll>> ves[500505];
struct node
{
	ll k;
	vector<ll> a,t;
}line[505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) 
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>line[i].k;
		for(int j=1;j<=line[i].k;j++)
		{
			ll a,t;
			cin>>a>>t;
			line[i].a.push_back(a);
			line[i].t.push_back(t);
			for(int k=0;k<j-1;k++)
			{
				ves[line[i].a[k]].push_back({a,line[i].t[k]+t});
				ves[a].push_back({line[i].a[k],line[i].t[k]+t});
			}
		}
	}
	for(int i=1;i<=m;i++) for(int j=1;j<=m;j++) dis[i][j]=inf;
	for(int i=1;i<=m;i++) for(auto j:ves[i]) dis[i][j.first]=min(dis[i][j.first],j.second);
	for(int i=1;i<=m;i++) dis[i][i]=0;
	for(int k=1;k<=m;k++) 
	{
		for(int i=1;i<=m;i++) 
		{
			if(dis[i][k]>=inf) continue;
			for(int j=1;j<=m;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		}
	}
	while(q--)
	{
		cin>>x>>y;
		cout<<w[x]+w[y]+dis[x][y]<<endl;
	}
	return 0;
}
