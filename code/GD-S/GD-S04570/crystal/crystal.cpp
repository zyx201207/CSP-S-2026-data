#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10,M=1e4+10;	
int n,m;
int a[N];
int sum;
int ans=INT_MIN;
int f[N];
int dp[M][M];

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	if(n<N){
		for(int i=1;i<=n;i++) cin>>a[i];
	
	sort(a+1,a+n+1);
	
	f[1]=a[1];
	for(int i=2;i<=n;i++)
		f[i]=f[i-1]+a[i];
	
	int ans=INT_MIN;
	for(int i=1;i<=n;i++)dp[1][i]=i*a[i]-f[i];	
	for(int i=2;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			dp[i][j]=j*a[j]-f[j]-f[i];
			
		}
			
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int cnt=j-i+1;
			if(dp[i][j]<=m)ans=max(cnt,ans);
		}
	}
		

	cout<<ans;
	}else{
		for(int i=1;i<=n;i++) cin>>a[i];
	
	sort(a+1,a+n+1);
	
	f[1]=a[1];
	for(int i=2;i<=n;i++)
		f[i]=f[i-1]+a[i];
		
	for(int i=2;i<=n;i++)
		f[i]=i*a[i]-f[i];
	
	for(int i=1;i<=n;i++)
		if(f[i]<=m)
			ans=max(ans,i);

	cout<<ans;
	}
	

	return 0;
	//predictive mark:45-50
}
/*

*/
