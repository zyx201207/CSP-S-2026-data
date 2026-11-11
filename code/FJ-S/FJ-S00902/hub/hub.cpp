#include<bits/stdc++.h>
using namespace std;
bool a[10086];int n,k;
vector<int>g[1000001]; 
int ans=INT_MAX;int dp[501][501];
int cnt=0;
int down(int x,int fa){
	int tim=0;
	bool is=0;
	for(auto i:g[x]){
		if(i==fa)continue;
		tim++;
		is|=a[i];
		down(i,x); 
	}
	
	if(!is||(tim==0&&a[x]))cnt++;
}
void dfs(int x,int l){
	if(x>k){
		int mx=0;
		cnt=0;
		
		//cout<<cnt<<"\n";
		if(cnt>2)return ;
		for(int i=1;i<=n;i++){
			//cout<<a[i]<<" ";
			if(a[i])continue;
			int mi=INT_MAX;
			for(int j=1;j<=n;j++){
				if(a[j])
				mi=min(mi,dp[i][j]);
			}
			mx=max(mx,mi);
		}
	
		ans=min(ans,mx);
		return ;
	}
	if(l>=n){
		return ;
	}
	
	for(int i=l+1;i<=n;i++){
		a[i]=1;
		dfs(x+1,i);
		a[i]=0;
	}
}

void work(){
	ans=INT_MAX;
	memset(a,0,sizeof a);
	memset(dp,0x3f,sizeof dp);
	for(int i=1;i<=500;i++)dp[i][i]=0;
	for(int i=1;i<=(int)1e6;i++)g[i].clear();
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		dp[u][v]=dp[v][u]=1;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			} 
		}
	}
	
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<"\n";
	}*/
	
	dfs(1,0);
	cout<<ans<<"\n";
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	//或许是重心
	int c,t;
	cin>>c>>t; 
	while(t--){
		work();
	}
	return 0;
}
