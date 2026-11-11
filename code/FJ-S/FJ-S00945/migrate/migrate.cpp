#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N=2e6+5;

struct node{
	int u;
	ll cnt;
};

int c,t;
int n;
ll d,x[10005],ans;
bool vis[10005];
ll dp[10005];
vector<int>mp[10005];
ll dist[10005];

void bfs(int s){
	memset(vis,0,sizeof vis);
	memset(dp,0,sizeof dp);
	memset(dist,-1,sizeof dist);
	
	queue<node>q;
	q.push({s,0});
	dp[s]=1;
	while(!q.empty()){
		node t=q.front();q.pop();
		ll u=t.u,cnt=t.cnt;
		if(vis[u]){
			continue;
		}
		vis[u]=1;
		
		for(int v:mp[u])if(!vis[v]){
			if(dist[v]==-1){
				dist[v]=cnt+1;
			}
			if(dist[v]==cnt+1){
				dp[v]+=dp[u];
			}

			q.push({v,cnt+1});
		}
	}
	
	for(int i=1;i<=n;i++){
		//cout<<dp[i]<<'\n';
		if(dp[i]==2){
			ans++;
			//cout<<s<<" "<<i<<'\n';
		}
	}
}

void slv1(){
	for(int i=1;i<=5000;i++)mp[i].clear();
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(x[j]-x[i]<=d){
				mp[i].push_back(j);
				//cout<<i<<" "<<j<<'\n';
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		bfs(i);
		//if(i==1)cout<<dp[6]<<'\n';
	}
	
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		//cout<<"\n\n\n\n\n\n\n\n";
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++)cin>>x[i];
		sort(x+1,x+1+n);
		slv1();
	}
	return 0;
} 
