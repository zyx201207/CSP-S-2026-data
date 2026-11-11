#include<bits/stdc++.h>
using namespace std;
int a[500101];
long long d[511][511];
vector<pair<int,int>> b[500101];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int n,m,q;
	cin>>n>>n>>m>>q>>q;
	for(int i1=1;i1<=m;i1++)
		cin>>a[i1];
	for(int i1=1;i1<=n;i1++)
	{
		int u;
		cin>>u;
		for(int i2=1;i2<=u;i2++)
		{
			int v,w;
			cin>>v>>w;
			b[v].push_back({i1,w});
		}
	}
	for(int i1=1;i1<=n;i1++)
		for(int i2=1;i2<=n;i2++)
			d[i1][i2]=1e16;
	for(int i1=1;i1<=n;i1++)
		d[i1][i1]=0;
	for(int i1=1;i1<=m;i1++)
		for(int i2=0;i2<b[i1].size();i2++)
			for(int i3=0;i3<b[i1].size();i3++)
				if(i2!=i3)
					d[b[i1][i2].first][b[i1][i3].first]=min(d[b[i1][i2].first][b[i1][i3].first],0ll+b[i1][i2].second+b[i1][i3].second);
	for(int i1=1;i1<=n;i1++)
		for(int i2=1;i2<=n;i2++)
			for(int i3=i2+1;i3<=n;i3++)
				d[i2][i3]=d[i3][i2]=min(d[i2][i3],d[i2][i1]+d[i1][i3]);
	while(q--)
	{
		int x,y;
		long long c=1e18;
		cin>>x>>y;
		for(int i1=0;i1<b[x].size();i1++)
			for(int i2=0;i2<b[y].size();i2++)
				c=min(c,0ll+a[x]+a[y]+b[x][i1].second+b[y][i2].second+d[b[x][i1].first][b[y][i2].first]);
		cout<<c<<'\n';
	}
	return 0;
}
