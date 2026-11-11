#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,m;
ll a[1000100];
ll ans[1000100];

void solve(){
	cin >> n >> m;
	for(ll i = 1;i<=n;i++){
		cin >> a[i];
		ans[a[i]]++;
	}
	for(ll i = 2;i<=m;i++){
		ans[i] += ans[i-1];
	}
	for(ll i = 1;i<=m;i++)cout << ans[i] << ' ';
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	solve();
	return 0;
} 
