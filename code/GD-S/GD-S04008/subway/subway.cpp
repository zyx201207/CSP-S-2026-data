#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
const int N=505,M=5e5+5;
const ll inf=1e18;
int C,n,m,d,Q,a[M];
struct node{
	int v,w;
};
vector<node>b[N],c[M];
ll f[N][N],ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>C>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int len;cin>>len;
		while(len--){
			int v,w;
			cin>>v>>w;
			b[i].push_back((node){v,w});
			c[v].push_back((node){i,w});
		}
		for(int j=1;j<=n;j++)if(j!=i)f[i][j]=inf;
	}
	for(int i=1;i<=n;i++)
		for(auto u:b[i])
			for(auto v:c[u.v]){
				f[i][v.v]=min(f[i][v.v],(ll)u.w+v.w),
				f[v.v][i]=min(f[v.v][i],(ll)u.w+v.w);
			}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)if(f[i][k]<inf){
			for(int j=1;j<=n;j++)if(f[k][j]<inf){
				ll w=f[i][k]+f[k][j];
				if(w<f[i][j])f[i][j]=w;
			}
		}
	while(Q--){
		int u,v;cin>>u>>v;
		ans=inf;
		for(auto x:c[u])
			for(auto y:c[v])
				ans=min(ans,f[x.v][y.v]+x.w+y.w);
		cout<<ans+a[u]+a[v]<<"\n";
	}
	return 0;
}
