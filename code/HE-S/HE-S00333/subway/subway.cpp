#include<bits/stdc++.h>
using namespace std;
int dp[500005];int w[500000+10];
vector<int>g[500050];
int flag[500050];
int dijk(int s,int e){
	memset(flag,0,sizeof(flag));
	memset(dp,0x3f,sizeof(dp));
	queue<pair<int,int> >q;q.push({s,w[s]});
	flag[s] = 1;
	while(!q.empty()){
		int u = q.front().first,v = q.front().second;q.pop();
		for(int i = 0,p;i < g[u].size();i++,p = g[u][i]){
			
			dp[p] = min(dp[p],v+w[p]);
			q.push({p,dp[p]});
		}
	}
	return dp[e];
	
}
int main(){

		
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	int c,n,m,d,q;cin >> c >> m >> d >> q;
	;memset(g,0,sizeof(g));memset(dp,0x3f,sizeof(dp));
	for(int i = 1;i <= m;i++) {
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		
		int k;cin >> k;
		int u;
		for(int j = 1;j <= k;j++){
			
			int a,t;cin >> a >> t;
				
		
			g[u].push_back(a);g[a].push_back(u);
		}	
	}
	for(int i = 0;i < q;i++){
		int x,y;cout << dijk(x,y) << endl;
		
	}
	
	
	
	return 0;
} 
