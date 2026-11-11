#include<bits/stdc++.h> 
using namespace std;
int a[500010];int c,n,m,d,q;
long long dp[1010][1010];
long long dfs(int x,int y){
	long long ans=100000000000000;
	for(int i=0;i<m;i++){
		if(dp[x][i]){
			ans=min(ans,dfs(i,y));
		}
	}
	return ans;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
   cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		int k;cin>>k;
		if(k<=2){
		int x;long long t1,t2;int y;
		cin>>x>>y>>t1>>t2;
		dp[x][y]=max(dp[x][y],t1+t2);
		dp[y][x]=max(dp[y][x],t1+t2);
		}
		}
	for(int i=0;i<q;i++){
		int x,y;cin>>x>>y;
		long long ans=dfs(x,y);
		cout<<ans<<endl;
	}
	
	return 0;
}
