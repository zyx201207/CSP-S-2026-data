#include<bits/stdc++.h>
using namespace std;
#define maxn 500005
#define maxm 505
#define ll long long
#define frp freopen
#define fio(in,out) frp(in,"r",stdin),frp(out,"w",stdout)
void bug(){cout<<endl;}
template<typename T,typename ... Ts>
void bug(T x,Ts ... y){cout<<x<<" ",bug(y...);}
template<typename T=int>
T read(){
	T res=0,f=1;char c;
	for(;(c=getchar())<'0'||c>'9';c=='-'?f=-f:0);
	while(c>='0'&&c<='9')res=(res<<3)+(res<<1)+c-'0',c=getchar();
	return res*f;
}
int n,m,q,val[maxn],head[maxn+maxm],to[maxn+maxm<<1],nxt[maxn+maxm<<1],w[maxn+maxm<<1],tot;
ll g[maxm][maxm];
void add(int u,int v,int d){to[++tot]=v,nxt[tot]=head[u],head[u]=tot,w[tot]=d;}
int main(){
	fio("subway.in","subway.out");
	int i,j,k;
	read(),n=read(),m=read(),read(),q=read();
	for(i=1;i<=m;++i)val[i]=read();
	for(i=1;i<=n;++i){
		int k=read();
		while(k--){
			int x=read()+n,t=read();
			add(x,i,t),add(i,x,t); 
		}
	}
	memset(g,63,sizeof(g));
	for(i=1;i<=n;++i)g[i][i]=0;
	for(int u=1;u<=n;++u){
		for(i=head[u];i;i=nxt[i]){
			int k=to[i];
			for(j=head[k];j;j=nxt[j]){
				int v=to[j];
				g[u][v]=min(g[u][v],(ll)w[i]+w[j]);
			}
		}
	}
	for(k=1;k<=n;++k)for(i=1;i<=n;++i)for(j=1;j<=n;++j)
		g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
//	for(i=1;i<=n;++i,puts(""))for(j=1;j<=n;++j)printf("%lld ",g[i][j]);
	while(q--){
		int x=read()+n,y=read()+n;ll ans=LLONG_MAX;
		for(i=head[x];i;i=nxt[i])for(j=head[y];j;j=nxt[j]){
			ans=min(ans,w[i]+w[j]+g[to[i]][to[j]]);
		}
		printf("%lld\n",ans+val[x-n]+val[y-n]);
	}
	return 0;
}

