#include<bits/stdc++.h>
using namespace std;
int c,t,n,dis[2000006],cnt[2000006];
bool vis[2000006];
long long d,a[2000006],ans=0;
vector<int> e[2000006];
void bfs(int st){
	memset(dis,0,sizeof(dis));
	memset(vis,0,sizeof(vis));
	memset(cnt,0,sizeof(cnt));
	queue<int> q;
	q.push(st);
	dis[st]=0;
	vis[st]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		int siz=e[u].size();
		for(int i=0;i<siz;i++){
			int v=e[u][i];
			if(v<u) continue;
			if(vis[v]==1){
				int x=dis[u]+1;
				if(x==dis[v]){
					cnt[v]++;
				} 
				if(x<dis[v]){
					dis[v]=x;
					cnt[v]=1;
				}
				continue;
			}
			dis[v]=dis[u]+1;
			vis[v]=1;
			q.push(v);
		}
	}
	for(int i=st+1;i<=n;i++) {
		cout<<"*"<<cnt[i]<<endl;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		ans=0;
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++){ 
			scanf("%lld",&a[i]);
			for(int j=i-1;j>=1;j--){
				if(a[i]-a[j]<=d){
					e[i].push_back(j);
					e[j].push_back(i);
				}else break;
			}
		}
		for(int i=1;i<=n-3;i++){
			bfs(i);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
