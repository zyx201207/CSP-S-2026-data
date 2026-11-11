#include<bits/stdc++.h>
using namespace std;
int c,T,head[1000005],cnt=1,n,k,ans,dis[3005][3005];
bool vis[1000005];
struct Edge{int nxt,to;}edge[2000005];
struct EDGE{int from,to;}kkk[2000005];
inline void addedge(int u,int v){edge[cnt].to=v;edge[cnt].nxt=head[u];head[u]=cnt++;}
inline void dfs(int u,int root,int fath){
	dis[root][u]=dis[root][fath]+1;
	if(u==root) dis[root][u]=0;
	for(int i=head[u];i;i=edge[i].nxt){
		int to=edge[i].to;
		if(to!=fath) dfs(to,root,u);
	}
}
inline void solve(){
	int ma=0;
	for(int i=1;i<=n;i++){
		int mi=0x3f3f3f3f;
		for(int j=1;j<=n;j++){
			if(vis[j]) mi=min(mi,dis[i][j]);
		}ma=max(ma,mi);
	}ans=min(ans,ma);
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;while(T--){
		cin>>n>>k;ans=0x3f3f3f3f;
		for(int i=1;i<=n;i++) head[i]=0;
		for(int i=1;i<=cnt;i++) edge[i]={0,0};cnt=1;
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;addedge(u,v);addedge(v,u);
			kkk[i]={u,v};
		}
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++) dis[i][j]=0;
		}
		for(int i=1;i<=n;i++) dfs(i,i,0);
		//for(int i=1;i<=n;i++){
			//for(int j=1;j<=n;j++) cout<<i<<" "<<j<<" "<<dis[i][j]<<"\n";
		//}
		for(int i=0;i<(1<<n);i++){
			int cnt=0,cnt1=0;
			for(int j=0;j<n;j++){
				vis[j+1]=(i>>j)&1;
				if(vis[j+1]) cnt++;
			}
			for(int j=1;j<n;j++){
				if(vis[kkk[j].from]&&vis[kkk[j].to]){
					cnt1++;
				}
			}
			if(cnt-cnt1<=2&&cnt==k) solve();
		}
		cout<<ans<<"\n";
	}
}
