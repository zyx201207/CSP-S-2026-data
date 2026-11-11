#include<bits/stdc++.h>
using namespace std;
typedef int intt;
#define int long long
const int maxn=2e6+10;
int c,t,n,d,x[maxn],ans,dis[maxn],dp[maxn];
int vis[maxn];
vector<int>g[maxn];
void dijkstra(int x){
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
	for(int i=1;i<=n;i++)dis[i]=0x3f3f3f3f3f3f3f3f,vis[i]=dp[i]=0;
	dis[x]=0;pq.push({0,x});dp[x]=1;
	while(!pq.empty()){
		int tmp=pq.top().second;pq.pop();
		if(vis[tmp])continue;vis[tmp]=1;
		for(int i=0;i<g[tmp].size();i++){
			if(dis[g[tmp][i]]>dis[tmp]+1){
				dis[g[tmp][i]]=dis[tmp]+1;dp[g[tmp][i]]=dp[tmp];
				pq.push({dis[g[tmp][i]],g[tmp][i]});
			}
			else if(dis[g[tmp][i]]==dis[tmp]+1){dp[g[tmp][i]]+=dp[tmp];}
		}
	}
	for(int i=1;i<=n;i++)if(dp[i]==2)ans++;
} 
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;ans=0;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(abs(x[i]-x[j])<=d)g[i].push_back(j);
			}
		}
//		dijkstra(1);
		for(int i=1;i<=n;i++)dijkstra(i);
		cout<<ans/2<<"\n";
		for(int i=1;i<=n;i++)g[i].clear();
	}
	return 0;
}



/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/ 



