#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
const ll N=2e5+9;
ll n,m;
ll a[N];
ll ans;
void dfs(ll x,ll left,ll sum){
	if(x>n&&left<=0){
		ans=max(ans,sum);
		return;
	}else if(x>n){
		return;
	}
	dfs(x+1,left,sum);
	if(sum==0&&left>0){
		dfs(x+1,left-1,a[x]);
	}else if(left>0){
		dfs(x+1,left-1,sum&a[x]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n>>m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	dfs(1,m,0);
	cout<<ans;
	return 0;
}

