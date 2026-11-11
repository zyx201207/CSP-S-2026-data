#include<bits/stdc++.h>
using namespace std;
int n;
long long m; 
long long a[500001],b[500001];
long long c[500001];
int dp[500001]; 
int l,r;
int ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	b[1]=0;
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];c[i]=c[i-1]+b[i]*i;
 	}
 	int cnt=1;
	for(int i=1;i<=n;i++){
		if(c[i]<=m){
			dp[i]=i;continue;
		} 
		while((c[i]-c[cnt]-cnt*(a[i]-a[cnt]))>m) cnt++;
		dp[i]=max(i-cnt+1,dp[i-1]);
	}
	cout<<dp[n];
	return 0;
}
