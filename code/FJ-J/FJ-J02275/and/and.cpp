#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int n,m,a[200010],dp[2010][2010],ans,flag;//dp[i][j]表示到第j位为止已选i个数的最大按位与
bool check(int x){
	if(x==2) return 1;
	while(x){
		if(x%2==0){
			x/=2;
		}else{
			return 0;
		}
	}
	return 1;
} 
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[1][i]=a[i];
		if(!check(a[i]+1)) flag=1;
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans<<endl;
		return 0;
	} 
	if(flag==0){
		sort(a+1,a+n+1,cmp);
		cout<<a[m]<<endl;
		return 0;
	}
	for(int j=2;j<=n;j++){
		for(int i=2;i<=m;i++){
			for(int k=1;k<j;k++){
				dp[i][j]=max(dp[i][j],dp[i-1][k]&a[j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,dp[m][i]);
		//cout<<i<<" "<<dp[m][i]<<endl;
	}
	cout<<ans<<endl;
//	for(int j=1;j<=n;j++){
//		for(int i=1;i<=m;i++){
//			cout<<dp[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	return 0;
} 
