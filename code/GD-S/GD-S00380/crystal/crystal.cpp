#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m;
vector<ll> a;
ll result = 0;

void improve_programme_speed(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
}

void input(){
	cin>>n>>m;
	a.resize(n + 1);
	for (ll i = 1;i <= n;i++){
		cin>>a[i];
	}
}

void solve(){
	sort(a.begin(), a.end());
	
	for (ll i = 1;i <= n;i++){
		ll ans = 1, limit = m; 
		for (ll j = 1;j < i;j++){
			ll num = a[i] - a[j];
			if (num <= limit){
				ans++;
				limit -= num;
			}
			else{
				break;
			}
		}	
		result = max(result, ans);
	}
}

void output(){
	cout<<result<<endl;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	improve_programme_speed();
		
	input();
	
	solve();
	 
	output();
	
	return 0;
}
