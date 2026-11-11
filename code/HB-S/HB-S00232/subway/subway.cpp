#include<bits/stdc++.h>
using namespace std;
namespace std{
	using i64=long long;
	using u32=unsigned int;
	using u64=unsigned long long;
	using p32=pair<int,int>;
	using p64=pair<long long,long long>;
	#define all(x) (x).begin(),(x).end()
	#define one(x) (x).first
	#define two(x) (x).second
}
#define int long long
int n,m,q,D,CASE;
vector<int> A[2][500005];
int a[500005],E[505][505],dis[505][505];
int solve(int x,int y){
	int ans=0x3f3f3f3f3f3f3f3f;
	for(int i=0;i<A[0][x].size();i++)
		for(int j=0;j<A[0][y].size();j++)
			ans=min(ans,dis[A[0][x][i]][A[0][y][j]]+A[1][x][i]+A[1][y][j]+a[x]+a[y]);
	return ans;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>CASE>>n>>m>>D>>q;
	for(int i=1;i<=m;i++)	cin>>a[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++)
			{int x,y;cin>>x>>y;A[0][x].push_back(i);A[1][x].push_back(y);}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			E[i][j]=0x3f3f3f3f3f3f3f3f;
	for(int i=1;i<=n;i++)	E[i][i]=0;
	for(int i=1;i<=m;i++)
		for(int j=0;j<A[0][i].size();j++)
			for(int k=0;k<A[0][i].size();k++)
				{int x=A[0][i][j],y=A[0][i][k];E[x][y]=min(E[x][y],A[1][i][j]+A[1][i][k]);}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=E[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
	while(q--){int x,y;cin>>x>>y;cout<<solve(x,y)<<"\n";}
	return 0;
}