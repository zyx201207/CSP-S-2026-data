#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int n, ans, k[N];
char c[N];
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> k[i] >> c[i];
	int l = 1, r = n;
	while(l < r){
		if(k[l] == k[r]){
			if(c[l] == c[r]){
				l++;
				r--;
			}else{
				ans += k[l];
				l++;
				r--;
			}
		}else if(k[l] > k[r]){
			if(c[l] == c[r]){
				k[l] -= k[r];
				r--;
			}else{
				ans += k[r];
				k[l] -= k[r];
				r--;
			}
		}else{
			if(c[l] == c[r]){
				k[r] -= k[l];
				l++;
			}else{
				ans += k[l];
				k[r] -= k[l];
				l++;
			}
		}
	}
	cout << ans;
	return 0;
}
