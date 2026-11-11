#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAXN=2*1e5+10;
ll n,k,a[MAXN],dp[2][MAXN];

ll f(ll x){
	if(x==0) return 1;
	else return 0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++) dp[1][i]=max(a[i],dp[1][i-1]);
	for(ll i=2;i<=k;i++){
		for(ll j=1;j<=n;j++){
			if(j<i) dp[i%2][j]=0;
			else{
				dp[i%2][j]=max(dp[i%2][j-1],dp[f(i%2)][j-1] & a[j]);
			}
		}
	}
	cout<<dp[k%2][n];
	return 0;
}
