#include<bits/stdc++.h>
#define ll long long 
#define pll pair<ll,ll> 
#define fi first
#define se second
#define mkp make_pair
using namespace std;
const int M=5e5+5,N=505;
const ll inf=1e18;
vector<pll> e[M],w[N];
int c,n,m,d,q,st,ed;
ll bg[M],ans;
int a,t;
ll f[2][N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=m;i++) cin>>bg[i];
	for(int i=1;i<=n;i++){	
		f[0][i][i]=0;
		int num;
		cin>>num;
		for(int j=1;j<=num;j++){
			cin>>a>>t;
			e[a].push_back(mkp(i+m,t));
			w[i].push_back(mkp(a,t));
		}
	}
	for(int i=1;i<=m;i++){
		for(auto pr:e[i]){
			int y=pr.fi,wy=pr.se;
			for(auto pr1:e[i]){
				int z=pr1.fi,wz=pr1.se;
				if(y==z) continue;
				f[0][y-m][z-m]=f[0][z-m][y-m]=wy+wz;
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[k&1][i][j]=min(f[(k&1)^1][i][j],f[(k&1)^1][i][k]+f[(k&1)^1][k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>st>>ed;
		ans=inf;
		for(auto pr:e[st]){
			int y=pr.fi-m,wy=pr.se;
			for(auto pr1:e[ed]){
				int z=pr1.fi-m,wz=pr1.se;
				ans=min(ans,wy+wz+f[n&1][y][z]);
			}
		}
		cout<<ans+bg[st]+bg[ed]<<'\n';
	}
	return 0; 
} 
