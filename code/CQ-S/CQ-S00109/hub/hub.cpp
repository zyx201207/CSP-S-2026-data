#include<bits/stdc++.h>
//#define int long long
using namespace std;
int c,t,n,k,u,b,ans=INT_MAX,v[105],vis[105],dp[105];
vector<int>a[1000005];
void dfs(int id,int fa){
	vis[id]=1;
	for(int x:a[id]){
		if(!vis[x]&&v[x]&&x!=fa){
			dfs(x,id);
		}
	}
}
void bfs(int s){
	queue<int>q;
	memset(dp,0x3f,sizeof(dp));
	dp[s]=0;
	q.push(s);
	while(q.size()){
		int u=q.front();
		q.pop();
		if(!vis[u]){
			vis[u]=1;
			for(int x:a[u]){
				if(dp[x]>dp[u]+1){
					dp[x]=dp[u]+1;
					q.push(x);
				}
			}
		}
	}
	return ;
}
int solve(int s){
	int cnt=0;
	memset(v,0,sizeof(v));
	for(int i=0;i<n;i++){
		v[i+1]=(s>>i)%2;
		if(v[i+1]==1)cnt++;
	}
	//cout<<s<<' ';
	if(cnt!=k)return ans;
	cnt=0;memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++){
		if(v[i]&&!vis[i]){
			dfs(i,0);
			cnt++;
			//if(s==262)cout<<i<<'\n';
		}
	}
	if(cnt>2)return ans;
	int sum=0;
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		bfs(i);
		int minn=INT_MAX;
		for(int j=1;j<=n;j++){
			if(v[j])minn=min(minn,dp[j]);
		}
		sum=max(sum,minn);
	}
	return sum;
}
int main(){
	//ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)a[i].clear();
		for(int i=1;i<n;i++)cin>>u>>b,a[u].push_back(b),a[b].push_back(u);
		//cout<<(1<<n)-1<<'\n';
	//	cout<<solve(8)<<'\n';
		for(int s=0;s<=(1<<n)-1;s++){
		//	cout<<s<<'\n';
			int p=solve(s);
			ans=min(ans,p);
		}
		cout<<ans<<endl;			
		ans=INT_MAX;
	}
	return 0;
}

