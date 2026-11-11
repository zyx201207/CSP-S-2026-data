#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5, M = 3e5 + 5;
ll n, m, a[N], ans[M];
int main(){
//	/*
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
//	*/
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> n >> m;
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(n <= 500){
		vector<ll> v;
		v.resize(n + 5);
		for(ll i = 1; i <= n; i++){
			v.clear();
			for(ll j = i; j <= n; j++){
				ll k = a[j];
				for(ll l = i; l < j; l++){
					if(k == a[l]){
						v.clear();
						for(ll o = i; o < j; o++){
							if(a[o] == k) break;
							v.push_back(a[o]);
						}	
					} 
				}
				v.push_back(k);
			}
			for(ll j = 1; j <= n; j++){
				if(v[j]) ans[v[j]]++;
			}
		}
		for(ll i = 1; i <= m; i++){
			cout << ans[i] << ' ';
		}
	}
	return 0;
}
//估分：拉完了 
