#include<bits/stdc++.h>
using namespace std;
int cnt[50];
long long mp[200005];
bitset <200005> l;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, k;
	long long ans = 0ll;
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		l[i] = 1;
		cin >> mp[i];
		bitset <40> tol = mp[i];
		for(int j = 0; (1ll << j) <= mp[i]; j++){
			cnt[j] += tol[j];
		}
	}
	for(int i = 20; i >= 0; i--){
		for(int j = 0; j <= 32; j++){
			cnt[j] = 0;
		}
		for(int j = 1; j <= n; j++){
			if(l[j]){
				bitset <40> tol = mp[j];
				for(int t = 0; (1ll << t) <= mp[j]; t++){
					cnt[t] += tol[t];
				}
			}
		}
		if(cnt[i] >= k){
			ans += (1ll << i);
			for(int j = 1; j <= n; j++){
				if(!((1ll << i) & mp[j])){
					l[j] = 0;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
