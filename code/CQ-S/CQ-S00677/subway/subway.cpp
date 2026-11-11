#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0;bool f=0;char ch=getchar();
	while(ch<'0'||ch>'9')f^=(ch=='-'),ch=getchar();
	while('0'<=ch&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
const int Maxn=1e6+505,N=505,inf=1e18;
int optt,n,m,d,q;
int w[Maxn];
int f[505][505];
struct node{
	int whi,val;
};
vector<node>g[Maxn];
int G[505][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	optt=read();n=read();m=read();d=read();q=read();
	for(int i=0;i<=n+1;i++)for(int j=0;j<=n+1;j++){
		G[i][j]=inf;
	}
	for(int i=1;i<=n;i++)G[i][i]=0;
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1;i<=n;i++){
		int k=read();
		while(k--){
			int a=read(),t=read();
			g[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		for(node x:g[i])for(node y:g[i])if(x.whi!=y.whi){
			G[x.whi][y.whi]=min(G[x.whi][y.whi],x.val+y.val);
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
			G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
		}
	}
	while(q--){
		int u=read(),v=read();
		if(u==v){
			puts("0");continue;
		}int ans=inf;
		for(node x:g[u])for(node y:g[v]){
			ans=min(ans,w[u]+w[v]+x.val+y.val+G[x.whi][y.whi]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}//15:00

