#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N=1e5+5;
int n,a[N],m,ans=-1,sum,dp[2005][2005];
bool vis[N];
void dfs(int pos,int cnt,int k){
	if(k==m){
		ans=max(ans,cnt);
		return;
	}
	for(int i=pos+1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(cnt==0) dfs(i,a[i],1);
			else dfs(i,(cnt&a[i]),k+1);
			vis[i]=0; 
		}
	}
	return;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	memset(dp,-1,sizeof dp);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i][1]=a[i];
	}
	sort(a+1,a+1+n,greater<int>());
	sum=a[1];
	for(int i=2;i<=m;i++) sum&=a[i];
	if(n==m){
		cout<<sum;
		return 0;
	}
	if(n<=20) dfs(0,0,0);
	
	dp[0][0]=0;
	for(int j=2;j<=m;j++){
		for(int i=j;i<=n;i++){
			dp[i][j]=max(dp[i-1][j],dp[i][j-1]&a[j]); 
		}
	}
	for(int i=m;i<=n;i++)
		ans=max(ans,dp[i][m]);
	 
	cout<<max(ans,sum);
	return 0;
}
