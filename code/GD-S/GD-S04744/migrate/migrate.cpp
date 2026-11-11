//migrate
#include<bits/stdc++.h>
#define p_b push_back
typedef long long ll;
using namespace std;
const int N=5e3+55,inf=1e8;
int sub,t,n,dis[N];
ll d,a[N],dp[N];
bool vis[N];
vector<int>edge[N];
struct Node{
	int u,d;
	bool operator <(const Node &oth) const{
		return d>oth.d;
	}
};
priority_queue<Node>q;
void dijkstra(int st){
	memset(dis,0x3f,sizeof(dis));
	memset(dp,0,sizeof(dp));
	memset(vis,false,sizeof(vis));
	dis[st]=0,dp[st]=1;
	q.push((Node){st,0});
	while(!q.empty()){
		int u=q.top().u,d=q.top().d;
		q.pop();
		if(vis[u]) continue;
		for(int v:edge[u]){
			if(dis[u]+1<dis[v]){
				dis[v]=dis[u]+1;
				dp[v]=dp[u];
				q.push((Node){v,dis[v]});
			}
			else if(dis[u]+1==dis[v]){
				dp[v]+=dp[u];
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>sub>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			edge[i].clear();
			for(int j=i-1;j>=1;j--){
				if(a[i]-a[j]>d) continue;
				edge[j].p_b(i); 
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			dijkstra(i);//无负边权,无需势能处理 
			for(int j=i+1;j<=n;j++){
				if(dp[j]==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
Sub 1~10 ver.
*/
