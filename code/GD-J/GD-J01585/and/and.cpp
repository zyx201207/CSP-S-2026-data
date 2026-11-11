#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5;
ll a[N];
ll dp[N];
ll n,k;
void solve1(){
	memset(dp,0,sizeof dp);
	for(ll i=1;i<=n;i++){
		for(ll j=min(i,k);j>1;j--){
			dp[j]=max(dp[j],dp[j-1]&a[i]);
		}
		dp[1]=max(dp[1],a[i]);
	}
	cout<<dp[k];
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	solve1();
		
	fclose(stdin);
	fclose(stdout);
	return 0;
}
