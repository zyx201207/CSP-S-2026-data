#include<iostream>
#include<vector>
#include<queue>
#define ll long long
using namespace std;
const int N=505,M=500005,D=25;
const ll inf=0x3f3f3f3f3f3f3f3f;
int a[M];
ll f[N][N];
struct node{
	int v;
	ll t;
	bool operator<(const node &x)const{
		return t>x.t;//小根堆 
	}
};
vector<node>ve[M+N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1,k,x,y;i<=n;i++){
		cin>>k;
		while(k--){
			cin>>x>>y;//第i条线到x站需要时间y
			ve[x].push_back({i,y});//x站到i线 
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)f[i][j]=inf;
		f[i][i]=0;
	}
	for(int i=1;i<=m;i++){//O(md^2)
		int sz=ve[i].size();
		for(int j=0;j<sz;j++){
			int u=ve[i][j].v;
			for(int k=j+1;k<sz;k++){
				int v=ve[i][k].v;
				ll w=0ll+ve[i][j].t+ve[i][k].t;
				f[u][v]=min(f[u][v],w);
				f[v][u]=min(f[v][u],w);
			}
		}
	}
	for(int k=1;k<=n;k++){//floyd
		for(int i=1;i<=n;i++){
			if(f[i][k]==inf)continue;
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){//O(qd^2)
		int x,y;
		cin>>x>>y;
		int sz_x=ve[x].size(),sz_y=ve[y].size();
		ll ans=inf;
		for(int i=0;i<sz_x;i++){
			int u=ve[x][i].v;
			for(int j=0;j<sz_y;j++){
				int v=ve[y][j].v;
				ll w=0ll+ve[x][i].t+ve[y][j].t;
				ans=min(ans,w+f[u][v]);
			}
		}
		cout<<ans+a[x]+a[y]<<'\n';
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
