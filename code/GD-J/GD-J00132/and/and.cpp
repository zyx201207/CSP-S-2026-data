#include<bits/stdc++.h>
using namespace std;
inline int f(int num){
	int ans=0;
	for(;num;num>>=1)ans+=num&1;
	return ans;
}
inline bool cmp(int a,int b){
	int numa=f(a);
	int numb=f(b);
	if(numa!=numb)return numa>=numb;
	return a>b;
}
int n,m;
int a[200010];
int dp[20010][20010];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		dp[1][i]=a[i];
	}
	for(int i=2;i<=m;i++){
		for(int j=1;j<=n-i+1;j++){
			dp[i][j]=dp[i-1][j]&dp[i-1][j+1];
		}
	}
	int ans=0;
	for(int j=1;j<=n-m+1;j++){
		ans=max(ans,dp[m][j]);
	}
	cout<<ans<<'\n';
}

