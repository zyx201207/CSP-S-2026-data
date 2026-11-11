#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<long long,int>> q;
int m,vis[2009],w[2009],k[509],a1,t1,x,y;
long long dis[1209][1209],mp[1209][1209];
vector<long long> a[509],t[509];
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
		for(i=1;i<=m;i++){
			if(dis[u][i]>dis[u][u1]+mp[u1][i]){
				dis[u][i]=dis[u][u1]+mp[u1][i];
				q.push({-dis[u][i],i});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,d,q,i,j,l;
	scanf("%d%d%lld%d%d",&c,&n,&m,&d,&q);
	for(i=1;i<=m;i++) scanf("%d",w+i);
	memset(mp,0x3f,sizeof(mp));
	for(i=1;i<=n;i++){
		scanf("%d",k+i);
		m++;
		for(j=1;j<=k[i];j++){
			scanf("%d%d",&a1,&t1);
			a[i].push_back(a1);
			t[i].push_back(t1);
			for(l=0;l<j;l++){
				mp[a[i][l]][m]=min(mp[a[i][l]][m],t[i][l]);
				mp[m][a[i][l]]=min(mp[m][a[i][l]],t[i][l]);
			}
		}
	}
	for(i=1;i<=q;i++){
		scanf("%d%d",&x,&y);
		if(dis[x][y]) printf("%d\n",dis[x][y]+w[x]+w[y]);
		else{
			dijkstra(x);
			printf("%d\n",dis[x][y]+w[x]+w[y]);
		}
	}
	return 0;
}