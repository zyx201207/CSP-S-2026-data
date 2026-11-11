#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
const int N=505,M=5e5+5,inf=1e16,INF=1e18;
int C,n,m,d,q,f[N][N],w[M];
struct node{
	int dis,x;
};//x∫≈œﬂ or x∫≈’æÃ® 
vector<node> e[M];
vector<node> g[N];
inline void ckmin(int &x,int y){if(x>y)x=y;}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,arr,tim;j<=k;j++){
			cin>>arr>>tim;
			g[i].pb({tim,arr});
			e[arr].pb({tim,i});
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j) f[i][j]=inf;
	for(int i=1;i<=n;i++){
		for(auto it:g[i]){
			int dis=it.dis,x=it.x;
			for(auto itt:e[x]){
				int diss=itt.dis,xx=itt.x;
				ckmin(f[i][xx],dis+diss);
				ckmin(f[xx][i],dis+diss);
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				ckmin(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		int x,y,ans=INF;
		cin>>x>>y;
		for(auto A:e[x]){
			for(auto B:e[y]){
				ckmin(ans,w[x]+w[y]+A.dis+B.dis+f[A.x][B.x]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
