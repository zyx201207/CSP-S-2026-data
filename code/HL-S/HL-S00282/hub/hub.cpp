#include<bits/stdc++.h>
using namespace std;
const int N=20;
int C,T,n,m,ans;
vector<int> g[N];
int dis[N],vis[N],vis1[N];
void dfs(int x){
	if(vis1[x]) return;
	if(!vis[x]) return;
	vis1[x]=1;
			for(int k=0;k<g[x].size();k++){
				dfs(k);
			}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&C,&T);
	while(T--){
		scanf("%d%d",&n,&m);ans=1e9;
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			g[x].push_back(y);
			g[y].push_back(x);
		}
		for(int i=1;i<(1<<n);i++){
			memset(dis,0x3f,sizeof(dis));
			memset(vis,0,sizeof(vis));
			memset(vis1,0,sizeof(vis1));
			for(int j=0;j<n;j++){
				if(i&(1<<j)) vis[j+1]=1;
			}
			int cnt=0;
			for(int j=1;j<=n;j++) if(!vis1[j]&&vis[j]) dfs(j),cnt++;
//			cout<<cnt<<endl;
			if(cnt>2) continue;
			queue<int> q;while(q.size()) q.pop();
			for(int j=1;j<=n;j++) if(vis[j]) q.push(j),dis[j]=0;
			while(q.size()){
				int x=q.front();q.pop();
				for(int k=0;k<g[x].size();k++){
					int y=g[x][k];
					if(vis[y]) continue;
					vis[y]=1;
					dis[y]=dis[x]+1;
					q.push(y);
				}
			}
			int ma=0;
			for(int j=1;j<=n;j++){
				ma=max(ma,dis[j]);
			}
//			cout<<i<<" "<<ma<<endl;
			ans=min(ans,ma);	
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
gu gu ga ga
Oct31==Dec25?
18:03 kai shi kan D,mei shen me shi jian le,suo yi da bao li jiu pao lu le
*/
