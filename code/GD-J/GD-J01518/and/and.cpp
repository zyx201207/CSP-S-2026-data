#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000005],dp[1000005],ans=0;
bool vis=0;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>4)vis=1;
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	if(m==2){
		dp[1]=INT_MIN;
		for(int i=1;i<=n;i++){
			if(i>1)dp[i]=dp[i-1];
			for(int j=i+1;j<=n;j++){
				int x=a[i]&a[j];
				dp[i]=max(dp[i],x);
			}
		}
		cout<<dp[n];
		return 0;
	}
	if(n==m){
		for(int i=2;i<=n;i++){
			ans+=a[i]&a[i-1];
			a[i]=a[i]&a[i-1];
		}
		cout<<ans;
		return 0;
	}
	if(n==m+1){
		sort(a+1,a+n+1);
		for(int i=3;i<=n;i++){
			ans+=a[i]&a[i-1];
			a[i]=a[i]&a[i-1];
		}
		cout<<ans;
		return 0;
	}
	if(!vis){
		sort(a+1,a+n+1,cmp);
		for(int i=2;i<=m;i++){
			ans+=a[i]&a[i-1];
			a[i]=a[i]&a[i-1];
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
