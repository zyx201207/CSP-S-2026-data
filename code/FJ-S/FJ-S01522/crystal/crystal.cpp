#include<bits/stdc++.h>
using namespace std;
long long a[500005],dp[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dp[1]=0;
	for(int i=2;i<=n;i++){
		dp[i]=dp[i-1]+(a[i]-a[i-1])*(i-1);
		
	}
	long long ans=1,l=1;
	for(int r=1;r<=n;r++){
		while(dp[r]-(dp[l-1]+(a[r]-a[l-1])*(l-1))>m){
			l++;
		}
		ans=max(ans,r-l+1);
		//cout<<l<<' '<<r<<endl;
	}
	cout<<ans;
	return 0;
}
