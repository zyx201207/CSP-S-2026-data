#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5;
ll c,n,m,d,q;
ll w[N];
vector<ll> a[505],t[505];
void solve(){
	cin >> c >> n >> m >> d >> q;
	for(ll i = 1;i <= m;i++) cin >> w[i];
	for(int i = 1;i <= n;i++){
		ll k;
		cin >> k;
		for(int i = 1;i <= k;i++){
			ll ai,ti;
			cin >> ai >> ti;
			a[i].push_back(ai);
			t[i].push_back(ti);
	}
	for(int i = 1;i <= q;i++){
		int a,b;
		cin >> a >> b;
		cout << w[a] + w[b] + t[1][a] + t[1][b] << endl;
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int t = 1;
//	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
