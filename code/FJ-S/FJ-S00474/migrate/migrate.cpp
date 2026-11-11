#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,t;
int n;
ll d;
ll x[305];
vector<int>adj[305];
int dis[305],dp[305],in[305],tmp[305];
void topo(int rt){
	queue<int>q;
	for(int j=rt;j<=n;j++){
		tmp[j]=in[j];
		if(!tmp[j]) q.push(j);
	}
	while(q.size()){
		int u=q.front();
		q.pop();
		for(auto v:adj[u]){
			tmp[v]--;
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				dp[v]=dp[u];
			}
			else if(dis[v]==dis[u]+1) dp[v]+=dp[u];
			if(!tmp[v]) q.push(v);
		}
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
			adj[j].clear();
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d){
					adj[i].push_back(j);
					//adj[j].push_back(i);
				}
				else break;
			}
		}
//		for(int j=1;j<=n;j++){
//			cout<<adj[j].size()<<" ";
//			for(int k=0;k<adj[j].size();k++) cout<<adj[j][k]<<" ";
//			cout<<"\n";
//		}
		for(int i=1;i<=n;i++){
			memset(dis,0x3f,sizeof dis);
			memset(dp,0,sizeof dp);
			dis[i]=0;
			dp[i]=1;
			topo(i);
//			cout<<i<<" ";
//			for(int j=1;j<=n;j++) cout<<dp[j]<<" ";
//			cout<<"\n";
//			cout<<i<<"\n";
//			for(int j=i+1;j<=n;j++) cout<<dp[j]<<" ";
//			cout<<"\n";
			for(int j=i+1;j<=n;j++){
				if(dp[j]==2) ans++;
			}
			//cout<<ans<<"\n";
		}
		cout<<ans<<"\n";
	}
	return 0;
}
