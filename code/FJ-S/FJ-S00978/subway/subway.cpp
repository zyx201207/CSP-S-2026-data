#include<iostream>
#include<vector>
#define ll long long
#define PII pair<int,long long>
#define fi first
#define se second
#define mp make_pair
using namespace std;
const int N=505,M=5e5+5;
const ll INF=1e18;
int n,m,D,Q,tot;
int head[M],ver[M],Next[M];
ll d[N][N],a[M],edge[M];

inline void add_edge(int x,int y,ll z){
	ver[++tot]=y,edge[tot]=z,Next[tot]=head[x],head[x]=tot;
}

inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<48||c>57){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>=48&&c<=57){
		x=(x<<3)+(x<<1)+c-48;
		c=getchar();
	}
	return f==-1?-x:x;
}

void solve(){
	n=read(),m=read(),D=read(),Q=read();
	for(int i=1;i<=m;i++) a[i]=read();
	for(int i=1;i<=n;i++){
		int k=read();
		while(k--){
			int x=read(),y=read();
			add_edge(x,i,y);
		} 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) d[i][j]=(i==j?0:INF);
	}
	for(int i=1;i<=m;i++){
		for(int j=head[i];j;j=Next[j]){
			for(int k=Next[j];k;k=Next[k]){
				int x=ver[j],y=ver[k];
				d[x][y]=min(d[x][y],edge[j]+edge[k]);
				d[y][x]=min(d[y][x],edge[j]+edge[k]);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
		}
	}
	while(Q--){
		int x=read(),y=read();
		ll ans=INF;
		for(int i=head[x];i;i=Next[i]){
			for(int j=head[y];j;j=Next[j]) ans=min(ans,d[ver[i]][ver[j]]+edge[i]+edge[j]);
		}
		printf("%lld\n",ans+a[x]+a[y]);
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int o=read(),T=1;
	while(T--) solve();
	return 0;
}

