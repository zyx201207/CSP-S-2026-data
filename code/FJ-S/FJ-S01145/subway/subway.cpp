#include<bits/stdc++.h>
using ll=long long;
using namespace std;
template<typename T>
inline void read(T &sss){
	sss=0;char ccc=getchar();bool ooo=0;
	for(;!isdigit(ccc);ccc=getchar())
		if(ccc=='-') ooo=1;
	for(;isdigit(ccc);ccc=getchar())
		sss=sss*10+ccc-'0';
	sss=ooo?-sss:sss;
	return ;
}
const int N=510,M=5e5+10;
int a[M],b[M],c[M],h[M+N],top;
void A(int aa,int bb,int cc){
	a[++top]=h[aa];
	b[top]=bb;
	c[top]=cc;
	h[aa]=top;
	return ;
}
int id,n,m,d,q;
int k[N];
ll g[N][N],w[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(id),read(n),read(m),read(d),read(q);
	for(int i=1;i<=m;i++)
		read(w[i]);
	for(int u=1;u<=n;u++){
		read(k[u]);
		for(int j=1;j<=k[u];j++){
			int v,w;
			read(v),read(w);
			A(v,u,w);}
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			g[i][j]=g[j][i]=1e18+10;
	for(int i=1;i<=m;i++){
		for(int e1=h[i];e1;e1=a[e1])
		for(int e2=h[i];e2;e2=a[e2]){
			int u=b[e1],v=b[e2];
			if(u==v)
				continue;
			g[u][v]=g[v][u]=min(g[u][v],0ll+c[e1]+c[e2]);}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
		if(i!=k)
			for(int j=i+1;j<=n;j++)
				g[i][j]=g[j][i]=min(g[i][j],g[i][k]+g[k][j]);
	while(q--){
		int u,v;
		read(u),read(v);
		ll ans=1e18+10;
		for(int e1=h[u];e1;e1=a[e1])
		for(int e2=h[v];e2;e2=a[e2]){
			int uu=b[e1],vv=b[e2];
			ans=min(ans,c[e1]+c[e2]+g[uu][vv]);}
		printf("%lld\n",ans+w[u]+w[v]);
	}
	return 0;
}
//qwq
