#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PII;
const int N=2e5+10;
ll n,m,ans;
ll a[N];
map<PII,ll> dp;
ll maxx(ll x,ll y){
	if(x>=y) return x;
	else return y;
}
ll dfs(int step,int k){
	if(dp[make_pair(step,k)]) return dp[make_pair(step,k)];
	if(k==0&&step>n){
		return 0x7FFFFFFFFFFFFFFF;
	}
	if(step>n){
		return 0;
	}
	if(k==0){
		return 0;
	}
	return dp[make_pair(step,k)]=maxx(dfs(step+1,k-1)&a[step],dfs(step+1,k));
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	ans=dfs(1,m);
	cout<<ans;
	return 0;
}
