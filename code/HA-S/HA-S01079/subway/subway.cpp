#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,dd,q,a[1010],vis[100010],d[100010],ans[1010][1010],tot;
vector<pair<int,int> >ve[100010];
void dij(int s)
{
	for(int i=1;i<=tot;i++)
		d[i]=1e18,vis[i]=0;
	d[s]=0;
	priority_queue<pair<int,int> >q;
	q.push(make_pair(0,s));
	while(q.size())
	{
		int x=q.top().second;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(auto ny:ve[x])
		{
			int y=ny.first,z=ny.second;
			if(d[y]>d[x]+z)
			{
				d[y]=d[x]+z;
				q.push(make_pair(-d[y],y));
			} 
		}
	}
	for(int i=1;i<=n;i++)
		ans[s][i]=d[i];
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>m>>n>>dd>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	tot=n;
	for(int i=1;i<=m;i++)
	{
		int k,lst=0;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x,y;
			cin>>x>>y;
			ve[x].push_back(make_pair(++tot,y));
			ve[tot].push_back(make_pair(x,y));
			if(j>1) ve[tot].push_back(make_pair(tot-1,0)),ve[tot-1].push_back(make_pair(tot,0));
		}
	}
	for(int i=1;i<=n;i++)
		dij(i);
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<ans[x][y]+a[x]+a[y]<<endl;
	}
	
	return 0;
}
