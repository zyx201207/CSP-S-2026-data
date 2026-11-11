#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
vector<ll> g[2020202];
ll dist[5050][5050],num[5050][5050],a[2020202];
bool vis[5050][5050];
struct st{
	ll nd,wk;
};
void bfs(ll s){
	queue<st> q;
	q.push({s,0});
	while(!q.empty()){
		int u=q.front().nd,w=q.front().wk;
		q.pop();
		if(vis[s][u]){
			if(w==dist[s][u]) num[s][u]++;
			else continue;
		}
		vis[s][u]=true;
		dist[s][u]=w;
		for(int v:g[u]){
			q.push({v,w+1});
		}
	}
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d %d",&c,&t);
	while(t--){
		if(c==11||c==12){
			ll n,d;
			ll ans=0;
			scanf("%lld %lld",&n,&d);
			for(int i=1;i<=n;i++){
				scanf("%lld",a+i);
			}
			ll diff=d/(a[2]-a[1]);
			if(diff<=1){
				printf("0\n");
				continue;
			}
			for(ll i=1;i*diff+1<=n;i++){
				ans+=n-i*diff;
			}
			printf("%lld\n",ans);
		}else{
			memset(num,0,sizeof(num));
			memset(vis,0,sizeof(vis));
			ll n,d;
			ll ans=0;
			scanf("%lld %lld",&n,&d);
			for(int i=1;i<=n;i++){
				scanf("%lld",a+i);
				for(int j=i-1;j>0;j--){
					if(a[i]-a[j]>d) break;
					g[j].push_back(i);
				}
			}
			for(int i=1;i<=n;i++) bfs(i);
			for(int i=1;i<=n;i++){
				for(int j=1;j<i;j++){
					if(num[j][i]==1){
						ans++;
						//printf("%d %d\n",j,i);
					} 
					
				}
			}
			printf("%lld\n",ans);
			for(int i=1;i<=n;i++) g[i].clear();
		}
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
