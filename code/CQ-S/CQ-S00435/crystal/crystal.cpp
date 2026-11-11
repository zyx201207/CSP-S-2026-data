#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],dp[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dp[1]=a[1];
	int ans=1;
	for(int i=2;i<=n;i++){
		dp[i]=dp[i-1]+a[i];
	}
	for(int i=1,j=2;j<=n;){
		long long l=a[j]*(j-i+1),k=dp[j]-dp[i-1];
		if(l<k) {
			j++;
			continue;
		}
		if(l-k<=m){
			ans=max(ans,(j-i+1));
			j++;
		}
		else{
			i++;
		}
	}
	cout<<ans;
	return 0;
}

