#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int c,t;
bool vis[N];
int cnt[N][N],dis[N],a[N];
void bfs(int i,vector<int>g[]){
	memset(vis,0,sizeof(vis));
	memset(dis,0,sizeof(dis));
	queue<int>q;
	q.push(i);
	cnt[i][i]=vis[i]=1;
	dis[i]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto v:g[u]){
			if(!vis[v]){
				q.push(v);
				dis[v]=dis[u]+1;
				vis[v]=1;
				cnt[i][v]++;
			}else if(dis[u]+1==dis[v])
				cnt[i][v]++;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		vector<int>g[N];
		memset(cnt,0,sizeof(cnt));
		int n,d,ans=0;
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			int j=i;
			while(j>=1&&a[i]-a[j]<=d){
				g[j].push_back(i);
				g[i].push_back(j);
				j--;
			}
		}
		for(int i=1;i<=n;i++)
			bfs(i,g);
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(cnt[i][j]==2)
					ans++;
		printf("%d\n",ans);
	}
	return 0;
}
