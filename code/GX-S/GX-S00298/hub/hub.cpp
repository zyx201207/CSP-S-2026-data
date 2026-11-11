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
int max(int a,int b){return (b>a?b:a);}
int min(int a,int b){return (b<a?b:a);}
int c,t,n,k,h[1114514]={},ei,f[1114514][20]={},dep[1114514]={},p[1114514]={},ans;
bool tgs[1114514]={};
struct Edge{int to,nt;}E[2114514]={};
void dfs(int fa,int sn){
	f[sn][0]=fa,dep[sn]=dep[fa]+1;
	for(int i=1;i<20;i++) f[sn][i]=f[f[sn][i-1]][i-1];
	for(int i=h[sn];i;i=E[i].nt) if(E[i].to!=fa) dfs(sn,E[i].to);
}
int lca(int x,int y){
	if(dep[x]<dep[y]) x^=y,y^=x,x^=y;
	for(int i=19;i>=0;i--) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	if(x==y) return x;
	for(int i=19;i>=0;i--) if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),t=read();
	while(t--){
		n=read(),k=read(),ei=0,ans=1e9;
		for(int i=1;i<=n;i++) h[i]=0;
		for(int i=1,u,v;i<n;i++) u=read(),v=read(),E[++ei]={v,h[u]},h[u]=ei,E[++ei]={u,h[v]},h[v]=ei;
		dfs(0,1);
		if(k>2) for(int S=1,ii,mx,dc;S<(1<<n);S++){
			ii=mx=dc=0;
			for(int i=0;i<n;i++){
				if(S&(1<<i)) tgs[i+1]=1,p[ii++]=i+1;
				else tgs[i+1]=0;
			}
			if(ii!=k) continue;
			for(int i=0;i<ii;i++) if(!tgs[f[p[i]][0]]) dc++;
			if(dc>2) continue;
			for(int x=1,mn;x<=n;x++) if(!tgs[x]){
				mn=1e9;
				for(int i=0;i<ii;i++) mn=min(mn,dep[x]+dep[p[i]]-2*dep[lca(x,p[i])]);
				mx=max(mx,mn);
			}
			if(mx<ans) ans=mx;
		}
		else for(int u=1,mx;u<=n;u++) for(int v=1;v<=n;v++) if(u!=v){
			mx=0;
			for(int x=1;x<=n;x++) if(x!=u and x!=v) mx=max(mx,min(dep[x]+dep[u]-2*dep[lca(x,u)],dep[x]+dep[v]-2*dep[lca(x,v)]));
			if(mx<ans) ans=mx;
		}
		printf("%d",ans);
		if(t) printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
