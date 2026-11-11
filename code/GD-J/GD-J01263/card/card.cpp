#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=5e5+10;
ll n,m,flag[N],dp[N],a[N],v[N],ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		dp[i]++;
	}
	for(ll i=n;i>=1;i--){
		v[i]=flag[a[i]];
		flag[a[i]]=i;
	}
	for(ll i=1;i<=n;i++){
		if(!v[i]){
			ans[a[i]]+=dp[i];
			dp[i+1]+=dp[i];
		}else dp[v[i]]+=dp[i];
	}
	for(ll i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
