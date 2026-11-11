#include<stdio.h>
#include<algorithm>
const int N=2e6+5,M=4e3+5;
struct jie{int to,nxt;}a[N];
int C,t,n,m,head[N],cnt,dis[M][M],father[N];
auto get = [](int t) -> int {
	while(t^father[t]) t=father[t]=father[father[t]];
	return t;
};
auto add = [](int x,int y) -> void {
	a[++cnt]={y,head[x]};
	head[x]=cnt;
};
auto dfs = [](auto &&self,int st,int u,int fa) -> void {
	for(int i=head[u];i;i=a[i].nxt) if(a[i].to!=fa) dis[st][a[i].to]=dis[st][u]+1,self(self,st,a[i].to,u);
};
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&C,&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) head[i]=0;
		for(int i=1;i<=cnt;i++) a[i]={0,0};
		cnt=0;
		for(int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),add(x,y),add(y,x);
		for(int i=1;i<=n;i++) dfs(dfs,i,i,0);
		int ans=0x3f3f3f3f;
		for(int s=0;s<(1<<n);s++){
			if(__builtin_popcount(s)!=m) continue;
			for(int i=1;i<=n;i++) father[i]=i;
			for(int i=1;i<=n;i++){
				if(s>>i-1&1){
					for(int j=head[i];j;j=a[j].nxt) if(s>>a[j].to-1&1) father[get(a[j].to)]=get(i);
				}
			}
			int count=0;
			for(int i=1;i<=n;i++) if((s>>i-1&1)&&father[i]==i) count++;
			if(count>2) continue;
			int maxn=0;
			for(int i=1;i<=n;i++){
				int minn=0x3f3f3f3f;
				for(int j=1;j<=n;j++) if(s>>j-1&1) minn=std::min(minn,dis[i][j]);
				maxn=std::max(maxn,minn);
			}
			ans=std::min(ans,maxn);
		}
		printf("%d\n",ans);
	}
	return 0;
}
