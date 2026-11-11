#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=200005;
const ll M=1e8+5;
ll a[N];
ll dp[M];
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,ans,m,k=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			dp[k++]=a[i]&a[j];
		}
	}
	sort(dp+1,dp+k+1,cmp);
	ans=dp[1];
	for(int i=2;i<=m;i++)ans&=dp[i]; 
	cout<<ans;
	return 0;
} 
