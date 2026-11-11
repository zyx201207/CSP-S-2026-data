#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define N 505
#define M 500005
int read(){
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	int x=0;
	while('0'<=c&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x;
}
void write(int x){
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
using namespace std;
const int INF=1e18;
int C,n,m,D,Q,W[M],k[N];
vector<int>t[N];
vector<pii>xian[M];
int dis[N][N];
void Mi(int &x,int y){if(x>y) x=y;	}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	C=read(),n=read(),m=read(),D=read(),Q=read();
	for(int i=1;i<=m;i++) W[i]=read();
	int a;
	for(int i=1;i<=n;i++){
		k[i]=read();
		t[i].resize(k[i]+2);
		for(int j=1;j<=k[i];j++){
			a=read(),t[i][j]=read();
			xian[a].pb({i,j});
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j) dis[i][j]=INF;
	for(int i=1;i<=m;i++){
		for(pii x:xian[i]){
			for(pii y:xian[i])
				Mi(dis[x.fi][y.fi],t[x.fi][x.se]+t[y.fi][y.se]);			
		}
	}
//	for(int i=1;i<=n;i++){for(int j=1;j<=n;j++) cout<<dis[i][j]<<" "; cout<<endl;	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) Mi(dis[i][j],dis[i][k]+dis[k][j]);
	int u,v,ans,res;
	while(Q--){
		u=read(),v=read();
		ans=INF;
		for(pii x:xian[u]){
//			if(ans<=t[x.fi][x.se]) continue;
			res=INF;
			for(pii y:xian[v])
				Mi(res,dis[x.fi][y.fi]+t[y.fi][y.se]);
			Mi(ans,t[x.fi][x.se]+res);
//				Mi(ans,t[x.fi][x.se]+dis[x.fi][y.fi]+t[y.fi][y.se]);			
		}
		write(ans+W[u]+W[v]),putchar('\n');
	} 
    return 0;
}
