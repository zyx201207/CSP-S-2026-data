#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,x[2000005],dis[5005][5005],sum[5005][5005],vis[5005];
int head[5005],nxt[25000005],to[25000005],cnt;
void add(int u,int v){
	nxt[++cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}
queue<pair<int,int>>q;
void bfs(int s){
	memset(dis[s],31,sizeof(dis[s]));
	memset(vis,0,sizeof(vis));
	dis[s][s]=0,sum[s][s]=1;
	q.push({s,dis[s][s]});
	while(!q.empty()){
		auto u=q.front();
		q.pop();
		if(vis[u.first])continue;
		vis[u.first]=1;
		for(int i=head[u.first];i;i=nxt[i]){
			int v=to[i];
			if(dis[s][v]>dis[s][u.first]+1)dis[s][v]=dis[s][u.first]+1,q.push({v,dis[s][v]}),sum[s][v]=sum[s][u.first];
			else if(dis[s][v]==dis[s][u.first]+1)sum[s][v]+=sum[s][u.first];
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		memset(head,0,sizeof(head));
		memset(sum,0,sizeof(sum));
		cnt=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)
			scanf("%lld",&x[i]);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++)
				if(x[j]-x[i]<=d)add(i,j);
		}
		for(int i=1;i<=n;i++)
			bfs(i);
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(sum[i][j]==2)cnt++;
			}
		}
		printf("%lld\n",cnt);
	}
	return 0;
}

