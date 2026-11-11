#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#define int long long
using namespace std;
const int N = 505;
const int M = 5e5+5;
const long long maxn = 100000000000000000ll;
int c,n,m,d,Q;
int W[M];
struct node{
	int v,w;
};
vector<node> e[M];
int k,v,w;
int x,y;
long long T[N][N],ans;
void cal(){
	long long sum=0;
	ans=maxn;
	for(int i=0;i<e[x].size();i++){
		for(int j=0;j<e[y].size();j++){
			sum=W[x]+W[y]+e[x][i].w+e[y][j].w+T[e[x][i].v][e[y][j].v];
			ans=min(ans,sum);
		}
	}
}
void work(int x){
	for(int i=0;i<e[x].size();i++){
		for(int j=0;j<e[x].size();j++){
			if(i==j)continue;
			int p1=e[x][i].v,p2=e[x][j].v;
			T[p1][p2]=min(T[p1][p2],1ll*e[x][i].w+e[x][j].w);
			T[p2][p1]=min(T[p2][p1],1ll*e[x][i].w+e[x][j].w);
			//eg[++cnt]=(node2){e[x][i].v,e[x][j].v,e[x][i].w+e[x][j].w};
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)cin>>W[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>v>>w;
			e[v].push_back((node){i,w});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			T[i][j]=maxn;
		}
	}
//	cerr<<T[1][2]<<'\n';
	for(int i=1;i<=m;i++)work(i);
//	cerr<<T[1][2]<<'\n';
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			for(int k=1;k<=n;k++){
				T[i][j]=min(T[i][j],T[i][k]+T[k][j]);
			}
		}
	}
	while(Q--){
		cin>>x>>y;
		cal();
		cout<<ans<<'\n';
	}
	return 0;
}
