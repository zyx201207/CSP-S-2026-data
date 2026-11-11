#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e2+10,M=5e5+10,INF=1e18;
int FW,n,m,d,q,f[MAXN][MAXN],w[M];
void add(int x,int y,int z){
	f[x][y]=min(f[x][y],z);
	f[y][x]=min(f[y][x],z);
}
struct node{
	int X,Y;
};
vector<node> g[M];
char ch;
void rd(int &x){
	x=0,ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(f,0x3f3f3f3f,sizeof(f));
	rd(FW),rd(n),rd(m),rd(d),rd(q);
	for(int i=1;i<=m;i++) rd(w[i]);
	for(int i=1,x;i<=n;i++){
		rd(x),f[i][i]=0;
		for(int j=1,y,z;j<=x;j++) rd(y),rd(z),g[y].push_back({i,z});
	}
	for(int i=1;i<=m;i++){
		int k=g[i].size();
		for(int u=0;u<k;u++){
			int x=g[i][u].X,w1=g[i][u].Y;
			for(int v=u+1;v<k;v++){
				int y=g[i][v].X,w2=g[i][v].Y;
				add(x,y,w1+w2);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(i==k) continue;
			for(int j=1;j<=n;j++){
				if(i==j||j==k) continue;
				f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
			}
		}
	}
	while(q--){
		int x,y,ans=INF;
		rd(x),rd(y);
		for(int u=0;u<(int)g[x].size();u++){
			int fx=g[x][u].X,w1=g[x][u].Y;
			for(int v=0;v<(int)g[y].size();v++){
				int fy=g[y][v].X,w2=g[y][v].Y;
//				if(fx>fy) swap(fx,fy);
				ans=min(ans,f[fx][fy]+w1+w2);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
} 
