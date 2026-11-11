#include<bits/stdc++.h>
using namespace std;
const int M=2e5+5;
int a[M],n,m,dp[105];long long ans=0;
void f(int i){
	if(i>m)return;
	for(int j=1;j<=n;j++){
		if(dp[j]&a[j]>ans)ans=dp[j]&a[j];
		dp[j]&=a[j];
	}
}
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,greater<long long>());
	n=min(8,n);
	f(1);
	cout<<ans;
}
