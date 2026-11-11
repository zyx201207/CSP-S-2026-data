//Oct31==Dec25?
#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5,N=502;
const long long inf=1e17;
int c,n,m,d,q,x,y,k,w[M];
long long ans;
long long dis[N][N];
vector<pair<int,int> >a[M];
int main()
{
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)cin>>w[i];
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			dis[i][j]=dis[j][i]=inf;
	for(int i=1;i<=n;++i)
	{
		cin>>k;
		while(k--)
		{
			cin>>x>>y;
			for(int j=0;j<a[x].size();++j)
			{
				int id=a[x][j].first,val=a[x][j].second+y;
				if(val<dis[id][i])dis[id][i]=dis[i][id]=val;
			}
			a[x].push_back(make_pair(i,y));
		}
	}
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
				if(dis[i][j]>dis[i][k]+dis[k][j])
					dis[i][j]=dis[j][i]=dis[i][k]+dis[k][j];
	while(q--)
	{
		ans=inf;
		cin>>x>>y;
		for(int j=0;j<a[x].size();++j)
			for(int k=0;k<a[y].size();++k)
			{
				int id1=a[x][j].first,id2=a[y][k].first,val=a[x][j].second+a[y][k].second;
				ans=min(ans,dis[id1][id2]+val);
			}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
