#include <bits/stdc++.h> 
using namespace std;
int a[210000];
bool v[210000];
int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		v[i] = true;
	}
	int ans = 0;
	for (int i = 29; i >= 0; i--){
		int sum = 0;
		for (int j = 1; j <= n; j++){
			if (v[j] == true && ((a[j] >> i) & 1) == 1){
				sum++;
			}
		}
		if (sum >= m){
			ans += (1 << i);
			for (int j = 1; j <= n; j++){
				if (v[j] == true && ((a[j] >> i) & 1) == 0){
					v[j] = false;
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
