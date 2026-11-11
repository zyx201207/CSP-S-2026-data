#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 2000005
int C,T,n,k,head[N],tot=1,ans=LLONG_MAX,f[N];
int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
struct EDGE{int v,nt;}edge[N<<1];
void addedge(int x,int y){
	edge[tot].v=y,edge[tot].nt=head[x],head[x]=tot++;
	edge[tot].v=x,edge[tot].nt=head[y],head[y]=tot++;
}
int dfs(int x,int f,int i){
	if((i>>(x-1))&1){return 0;}
	int ans=LLONG_MAX/2;
	for(int j=head[x];j;j=edge[j].nt){
		int y=edge[j].v;
		if(y!=f) ans=min(ans,1ll+dfs(y,x,i));
//		cout<<x<<" "<<ans<<endl;cout<<x<<" "<<f<<" "<<i<<endl;
	}
//	cout<<x<<" "<<i<<" "<<f<<" "<<ans<<endl; 
	return ans;
}
signed main(){
//	freopen("hub2.in","r",stdin);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&C,&T);
	while(T--){
		scanf("%lld%lld",&n,&k),tot=1,ans=LLONG_MAX;
		for(int i=1;i<=n;i++) head[i]=0;
		for(int i=1,x,y;i<n;i++) scanf("%lld%lld",&x,&y),addedge(x,y);
		for(int i=0;i<(1<<n);i++){
			int cnt=0;
			for(int j=1;j<=n;j++) if(i&(1<<(j-1))) cnt++;
			if(cnt!=k) continue;
			for(int j=1;j<=n;j++) f[j]=j;
			for(int j=1;j<=n;j++){
				if((i>>(j-1))&1){
					for(int l=head[j];l;l=edge[l].nt){
						int y=edge[l].v;
						if((i>>(y-1))&1) f[find(y)]=find(j);
					}	
				}
			}
			cnt=0;
			for(int j=1;j<=n;j++) if(((i>>(j-1))&1)&&find(j)==j) cnt++;
			if(cnt>2) continue;
			int anss=0;
			for(int j=1;j<=n;j++) if(((i>>(j-1))&1)==0) anss=max(anss,dfs(j,0,i));
			ans=min(ans,anss);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
