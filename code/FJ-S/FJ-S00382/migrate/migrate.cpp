#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<int,int>> q;
int vis[5009],dis[5009][5009],mp[5009][5009],ans;
short cnt[5009][5009];
long long n,x[100009],d;
void dijkstra(int u){
	int i;
	memset(vis,0,sizeof(vis));
	memset(dis[u],0x3f,sizeof(dis[u]));
	dis[u][u]=0;
	q.push({0,u});
	while(!q.empty()){
		int u1=q.top().second;
		q.pop();
		if(vis[u1]) continue;
		vis[u1]=1;
		for(i=u1+1;i<=n;i++){
			if(dis[u][i]==dis[u][u1]+mp[u1][i]){
				if(cnt[u][i]==2) ans--;
				if(cnt[u][i]==1) ans++;
				cnt[u][i]++;
			}
			if(dis[u][i]>dis[u][u1]+mp[u1][i]){
				if(cnt[u][i]==2) ans--;
				cnt[u][i]=1;
				dis[u][i]=dis[u][u1]+mp[u1][i];
				q.push({-dis[u][i],i});
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,q,i,j,l;
	scanf("%d%d",&c,&t);
	while(t--){
		memset(mp,0x3f,sizeof(mp));
		memset(cnt,0,sizeof(cnt));
		ans=0;
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=n;i++) scanf("%lld",x+i);
		for(i=1;i<=n;i++){
			for(j=i-1;j>=1;j--){
				if(x[i]-x[j]<=d) mp[i][j]=mp[j][i]=1;
				else break;
			}
		}
		for(i=1;i<=n;i++){
			dijkstra(i);
		}
		printf("%d\n",ans);
	}
	return 0;
}