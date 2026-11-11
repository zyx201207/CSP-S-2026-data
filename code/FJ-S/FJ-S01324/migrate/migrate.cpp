#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n,d,x[N],dis[N],cnt[N],ans;
priority_queue<pair<int,int>> q;
queue<int> qu;
bool vis[N];
void dijkstra(int s){
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	dis[s]=0;
	q.push({0,s});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=u+1;i<=n;i++){
			if(x[i]-x[u]>d) break;
			if(dis[i]>dis[u]+1){
				dis[i]=dis[u]+1;
				q.push({-dis[i],i});
			}
		}
	}
}
void solve(int s){
	qu.push(s);
	cnt[s]=1;
	while(!q.empty()){
		int u=qu.front();
		qu.pop();
		for(int i=u+1;i<=n;i++){
			if(x[i]-x[u]>d) continue;
			if(dis[u]+1==dis[i]){
				cnt[i]+=cnt[u];
			}
		} 
	}
}
int main(){
	freopen("migrate1.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		ans=0;
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%d",&x[i]);
		}
		for(int i=1;i<=n;i++){
			dijkstra(i);
			solve(i);
			for(int j=i+1;j<=n;j++){
				if(cnt[j]==2) ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
