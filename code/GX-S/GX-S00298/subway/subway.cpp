#include<cstdio>
char buf[1<<24]={},*p1=buf,*p2=buf,ch;
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<24,stdin),p1==p2)?EOF:*p1++)
#define isD(ch) (48<=ch&&ch<=57)
int read(){
	int num=0;
	ch=gc();
	while(!isD(ch)) ch=gc();
	while(isD(ch)) num=(num<<3)+(num<<1)+(ch^48),ch=gc();
	return num;
}
long long min(long long a,long long b){return (b<a?b:a);}
int c,n,m,d,q,h[501145]={},ei=0;
long long w[501145]={},dis[514][514]={},mn;
struct Edge{
	int to,nt;
	long long w;
}E[1114514]={};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1,k,a,t;i<=n;i++){
		for(int j=1;j<=n;j++) dis[i][j]=(i!=j?1e18:0);
		k=read();
		while(k--) a=read(),t=read(),E[++ei]={a,h[m+i],t},h[m+i]=ei,E[++ei]={m+i,h[a],t},h[a]=ei;
	}
	for(int p=1,u,v;p<=m;p++) for(int i=h[p];i;i=E[i].nt){
		u=E[i].to-m;
		for(int j=h[p];j;j=E[j].nt) v=E[j].to-m,dis[u][v]=min(dis[u][v],E[i].w+E[j].w);
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int x,y,u,v;q--;){
		x=read(),y=read(),mn=1e18;
		for(int i=h[x];i;i=E[i].nt){
			u=E[i].to-m;
			for(int j=h[y];j;j=E[j].nt) v=E[j].to-m,mn=min(mn,E[i].w+E[j].w+dis[u][v]);
		}
		printf("%lld",mn+w[x]+w[y]);
		if(q) printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
