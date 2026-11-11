#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const ll MAX=2005;
ll n,m,dp[200005],a[200005],ans;
bool cmp(ll x,ll y){
	return x<y;
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;++i){
		dp[i]=dp[i-1]|a[i];
		//cout<<dp[i]<<endl;
	}
	for(int i=m;i<=n;++i){
		ans=max(ans,dp[i]&a[i-m+1]);
	} 
	cout<<ans;
	return 0;
}
/*
5 3
31 3 1 15 7
*/
