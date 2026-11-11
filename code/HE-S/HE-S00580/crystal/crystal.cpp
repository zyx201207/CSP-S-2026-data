#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],maxn = -1,t[267933931];
void dfs(ll step){
	if (step > m){
		ll ans = -2e18;
		for (ll i = 1;i<=n;i++){
			t[a[i]]++;
			ans = max(ans,a[i]);
		}
		for (ll i = 1;i<=ans;i++){
			maxn = max(maxn,t[i]);
			t[i] = 0;
		}
		return;
	}
	for (ll i = 1;i<=n;i++){
		a[i] += 1;
		dfs(step+1);
		a[i] -= 1;
	}
}


int main(){
	freopen("crystal.in","r",stdin);
	freopen("crytal.out","w",stdout);
	cin>>n>>m;
	for (int i = 1;i<=n;i++){
		cin>>a[i];
	}
	bool b = 1;
	for (int i = 2;i<=n;i++){
		if (a[i] - a[i-1] != 1){
			b = 0;
			break;
		}
	}
	if (b){
		cout<<m-1;
	}
	else{
		dfs(1);
		cout<<maxn;
	}
	return 0;
}
