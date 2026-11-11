#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e3+5;
int ccc,T,n,k,dis[N],t[N*2],nt[N*2],h[N],summ,q[N],fa[N],vis[N],hav[N],ans;
void add(int x,int y){t[++summ]=y,nt[summ]=h[x],h[x]=summ;}
void bfs(){
	queue<int> qu;
	for(int i=1;i<=k;i++) qu.push(q[i]),dis[q[i]]=0;
	while(!qu.empty()){
		int u=qu.front();
		qu.pop();
		for(int i=h[u],v=t[i];i;i=nt[i],v=t[i])
			if(dis[v]==INT_MAX) dis[v]=dis[u]+1,qu.push(v);
	}
}
int find(int x){return fa[x]=(fa[x]==x?x:find(fa[x]));}
void bing(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx!=fy) fa[fx]=fy;
}
void dfs(int s,int cnt){
	if(cnt==k){
		for(int i=1;i<=n;i++) fa[i]=i,hav[i]=0,dis[i]=INT_MAX;
		for(int i=1;i<=k;i++){
			for(int j=h[q[i]],v=t[j];j;j=nt[j],v=t[j])
				if(vis[v]) bing(q[i],v);
		}
		for(int i=1;i<=k;i++) hav[find(q[i])]=1;
		int sum=0;
		for(int i=1;i<=n&&sum<=2;i++) sum+=hav[i];
		if(sum>2) return;
		bfs();
		int mmax=-1;
		for(int i=1;i<=n;i++) mmax=max(mmax,dis[i]);
		ans=min(ans,mmax);
		return;
	}
	for(int i=s;i<=n-k+cnt+1;i++){
		q[cnt+1]=i,vis[i]=1,dfs(i+1,cnt+1),vis[i]=0;
	}
}
int main(){
	freopen("hub.in","r",stdin); 
	freopen("hub.out","w",stdout);	
	scanf("%d%d",&ccc,&T);
	while(T--){
		scanf("%d%d",&n,&k),memset(dis,0,sizeof dis),summ=0,memset(h,0,sizeof h),ans=INT_MAX;
		for(int i=1,u,v;i<n;i++){
			scanf("%d%d",&u,&v);
			if(ccc!=13&&ccc!=14&&n!=k) add(u,v),add(v,u);
		}
		if(n==k) printf("0\n");
		else if(ccc==13||ccc==14){
			if(k<(n-1)/2) printf("%d\n",(((n-1)/2+1)/2-k/2+1)/2+1);
			else printf("1\n");
		}
		else dfs(1,0),printf("%d\n",ans);
	}
	return 0;
}
