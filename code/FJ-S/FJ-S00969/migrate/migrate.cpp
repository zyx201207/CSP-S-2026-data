#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long dis[N],cnt[N],x[N],c,T,n,d;
bool vis[N];
vector<long long> g[N]; 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	scanf("%lld %lld",&c,&T);
	while(T--){
		scanf("%lld %lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		for(int i=1;i<=n;i++){
			g[i].clear();
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d){
					g[i].push_back(j);
					g[j].push_back(i);
				}
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
//			printf("%d:\n",i);
			memset(dis,0x3f,sizeof(dis));
			memset(cnt,0,sizeof(cnt));
			memset(vis,0,sizeof(vis));
			queue<long long> q;
			dis[i]=0;
			q.push(i);
			while(!q.empty()){
				long long u=q.front();
				q.pop();
				for(int v : g[u]){
					if(dis[v]>dis[u]+1){
						cnt[v]=1;
						dis[v]=dis[u]+1;
						q.push(v);
					}
					else if(dis[v]==dis[u]+1){
						cnt[v]++;
					}
				}
			} 
//			for(int j=1;j<=n;j++){
//				cout<<dis[j]<<endl;
//			}
			for(int j=i+1;j<=n;j++){
				if(cnt[j]==2){
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

