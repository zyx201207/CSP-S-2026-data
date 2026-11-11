#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e3+5;

int c;
int t,n;
ll d;
ll x[N];
ll dp[N];
int dist[N];
int cnt;
int head[N];

struct E{
	int to,nxt; 
}edge[N*N];

void add(int u,int v){
	++cnt;
	edge[cnt].to=v,edge[cnt].nxt=head[u];
	head[u]=cnt;
} 

void bfs(int s){
	queue<int>pq;
	pq.push(s);
	memset(dist,0x3f,sizeof(dist));
	memset(dp,0,sizeof(dp));
	dist[s]=0;
	dp[s]=1;
	while(!pq.empty()){
		int u=pq.front();
		pq.pop();
		for(int i=head[u];i;i=edge[i].nxt){
			int v=edge[i].to;
			if(dist[v]==0x3f3f3f3f){
				dist[v]=dist[u]+1;
				pq.push(v);
				dp[v]=1;
			}
			else if(dist[v]==dist[u]+1) dp[v]+=dp[u];
		}
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		cnt=0; 
		for(int i=1;i<=n;i++){
			cin>>x[i];
			head[i]=0;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j&&abs(x[i]-x[j])<=d) add(i,j);
			}
		}
		ll ans=0LL;
		for(int i=1;i<=n;i++){
			bfs(i);
			for(int j=i+1;j<=n;j++){
				if(dp[j]==2) ++ans;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
