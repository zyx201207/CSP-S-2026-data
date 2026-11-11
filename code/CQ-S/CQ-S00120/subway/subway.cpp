#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl "\n"
using namespace std;
const int N=505,M=5e5+10,INF=1e17;
int c,n,m,d,q,w[M],k[N],f[N][N];
vector<pii> a[M]; 
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int x,y;
			cin>>x>>y;
			a[x].push_back({i,y});
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j)f[i][j]=INF;
	for(int i=1;i<=m;i++)
	{
		for(auto [x,xx]:a[i])
		{
			for(auto [y,yy]:a[i])
			{
				if(x==y)continue;
				f[x][y]=min(f[x][y],xx+yy);
			}
		}
	}
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=n;j++)
//			printf("f[%lld][%lld]=%lld\n",i,j,f[i][j]);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int ans=INF;
		for(auto [i,ii]:a[x])
		{
			for(auto [j,jj]:a[y])
			{
				ans=min(ans,w[x]+w[y]+f[i][j]+ii+jj);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

32
17

*/

