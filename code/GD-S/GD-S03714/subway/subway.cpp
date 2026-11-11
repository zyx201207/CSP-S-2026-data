#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

//struct edge_t
//{
//	long long v,w,next;
//}edge[10000010];

long long C,n,m,D,q,/*head[1010],len,*/w[1000010],d[510][510];
vector<long long>a[1010],t[1010],idx[1000010],tdx[1000010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(d,0x3f,sizeof(d));
	cin>>C>>n>>m>>D>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		long long k;
		cin>>k;
		a[i].reserve(k+10);
		t[i].reserve(k+10);
		for(int j=0;j<k;j++)
		{
			long long aa,tt;
			cin>>aa>>tt;
			a[i].push_back(aa);
			t[i].push_back(tt);
			idx[aa].push_back(i);
			tdx[aa].push_back(tt);
		}
	}
//	for(int i=1;i<=m;i++)
//	{
//		cerr<<"|"<<i<<"|";
//		for(int j=0;j<idx[i].size();j++)cerr<<idx[i][j]<<" ";
//		cerr<<endl;
//	}
//	cerr<<"inited"<<endl;
	for(int i=1;i<=n;i++)
	{
		d[i][i]=0;
		for(int j=0;j<a[i].size();j++)
		{
//			cerr<<a[i][j]<<" "<<idx[a[i][j]].size()<<endl;
			for(int k=0;k<idx[a[i][j]].size();k++)
			{
				if(idx[a[i][j]][k]==i)continue;
				//if(k>50)return 1;
				//cerr<<i<<" "<<j<<" "<<k<<endl;
				//cerr<<"|d["<<i<<"]["<<idx[a[i][j]][k]<<"]=_min "<<t[i][j]+tdx[a[i][j]][k]<<endl;
				d[i][idx[a[i][j]][k]]=d[idx[a[i][j]][k]][i]=min(d[i][idx[a[i][j]][k]],t[i][j]+tdx[a[i][j]][k]);
			}
		}
	}
//	cerr<<"builded"<<endl;
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				if(d[i][k]+d[k][j]<d[i][j])d[i][j]=d[i][k]+d[k][j];
		}
	}
//	cerr<<"floyded"<<endl;
//	for(long long i=1;i<=n;i++)
//	{
//		cerr<<"|";
//		for(long long j=1;j<=n;j++)cerr<<d[i][j]<<" ";
//		cerr<<endl;
//	}
	while(q--)
	{
		long long x,y,ans=(1ll<<62);
		cin>>x>>y;
		for(int i=0;i<idx[x].size();i++)
		{
			for(int j=0;j<idx[y].size();j++)
			{
				ans=min(ans,tdx[x][i]+tdx[y][j]+d[idx[x][i]][idx[y][j]]);
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
