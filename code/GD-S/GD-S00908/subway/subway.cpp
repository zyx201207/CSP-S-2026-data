#include <bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+8;
//struct tmp_G{int t,x;long long t;} a[M<<1];
vector <pair<int,long long> > tmp_G[M];
long long dist[N][N],w[M];
int c,n,m,d,q;
//void add(int x,int y,long long z){
//	a[++Cnt]={h[x],y,z},h[x]=Cnt;
//	a[++Cnt]={h[y],x,z},h[y]=Cnt;
//}
void Floyed(){
	for (int i=0;i<N;++i) dist[i][i]=0;
	for (int k=1;k<=n;++k){
		for (int i=1;i<=n;++i){
			for (int j=1;j<=n;++j){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
}
void add(int x,int y,long long z){
	dist[y][x]=dist[x][y]=min(dist[x][y],z);
}
void Build(){
	for (int u=1;u<=m;++u){
		for (auto i:tmp_G[u]){
			for (auto j:tmp_G[u]){
				add(i.first,j.first,i.second+j.second);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >>c>>n>>m>>d>>q;
	memset(dist,0x3f,sizeof(dist));
	for (int i=1;i<=m;++i) cin >>w[i];
	for (int i=1,x,k;i<=n;++i){
		long long y;
		cin >>k;
		for (int j=1;j<=k;++j){
			cin >>x>>y;
			tmp_G[x].push_back(make_pair(i,y));
		}
	}
	Build();
	Floyed();
	while (q--){
		int x,y;
		cin >>x>>y;
		long long ans=0x3f3f3f3f3f3f3f3f;
		for (auto i:tmp_G[x]){
			for (auto j:tmp_G[y]){
				ans=min(ans,i.second+j.second+dist[i.first][j.first]);
			}
		}
		cout <<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
