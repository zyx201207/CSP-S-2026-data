#include<bits/stdc++.h>

using namespace std;

int c,t;
int n;
long long d;
long long a[2000007];
vector<int> g[2000007];

long long dis[2000007];
int cnt[2000007];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;

void dijkstra(int s){
	memset(dis,0x3f,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	while(!q.empty()) q.pop();
	dis[s]=0;
	cnt[s]=1;
	q.push({0,s});
	
	while(!q.empty()){
		int u=q.top().second,w=q.top().first;
		q.pop();
		if(dis[u]!=w) continue;
		
		for(auto i:g[u]){
			int v=i;
			if(w+1<dis[v]){
				dis[v]=w+1;
				cnt[v]=cnt[u];
				q.push({dis[v],v});
			}else if(w+1==dis[v]){
				cnt[v]+=cnt[u];
			}
		}
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	scanf("%d %d",&c,&t);
	
	while(t--){
		scanf("%d %lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(int i=1;i<=n;i++){
			g[i].clear();
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d) g[i].push_back(j);
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			dijkstra(i);
			for(int j=i+1;j<=n;j++){
				//cout<<i<<" "<<j<<" "<<cnt[j]<<endl;
				if(cnt[j]==2) ans++;
			}
		}
		printf("%d\n",ans);
	}
	
	return 0;
}
