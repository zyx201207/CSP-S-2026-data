#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=510,M=5e5+10;
const ll INF=1e18;
ll ans,f[N][N];
int c,n,m,d,q,head[M],cnt,a[M];
struct node{
	int nxt,v,w;
}e[M*20];
void add(int u,int v,int w){
	e[++cnt]={head[u],v,w};
	head[u]=cnt;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=INF;
			if(i==j)f[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int x,w;
			scanf("%d %d",&x,&w);
			for(int now=head[x];now;now=e[now].nxt){
				f[i][e[now].v]=min(f[i][e[now].v],(ll)(w+e[now].w));
				f[e[now].v][i]=min(f[e[now].v][i],(ll)(w+e[now].w));
			}
			add(x,i,w);
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		scanf("%d %d",&x,&y);
		ans=INF;
		for(int s=head[x];s;s=e[s].nxt){
			for(int t=head[y];t;t=e[t].nxt){
				ans=min(ans,f[e[s].v][e[t].v]+e[s].w+e[t].w+a[x]+a[y]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
