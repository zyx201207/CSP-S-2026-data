#include <bits/stdc++.h>
#define endl '\n'
#define fn "migrate"
typedef long long ll;
using namespace std;
int c, t;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen(fn ".in", "r", stdin);
	freopen(fn ".out", "w", stdout);
	cin >> c >> t;
	while(t --){
		ll n, d, a[2000020], ans = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i ++){
			cin >> a[i];
		}
		for (int i = 3; i <= n; i ++){
			if(a[i] - a[i - 2] <= d){
				ans += 2;
				if(i < n && a[i + 1] - a[i - 1] > d){
					ans += 2;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
