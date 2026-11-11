#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
using ll = long long;
int n;
ll a[N];
char c[N];


signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> a[i] >> c[i];
	}
	ll ans = 0;
	ll Left_cnt = a[1], Right_cnt = a[n];
	for(int i = 1, j = n; i < j; ) {
		if(c[i] == c[j]) {
			ll need_sumn = min(Left_cnt, Right_cnt);
			Left_cnt -= need_sumn;
			Right_cnt -= need_sumn; 
		}
		else {
			if(Left_cnt <= Right_cnt) {
				Right_cnt -= Left_cnt;
				ans += Left_cnt;
				Left_cnt = 0;
			}
			else {
				Left_cnt -= Right_cnt;
				ans += Right_cnt;
				Right_cnt = 0;
			}
		}
		if(Left_cnt == 0) {
			i++;
			Left_cnt = a[i];
		}
		if(Right_cnt == 0) {
			j--;
			Right_cnt = a[j];
		}
	}
	cout << ans;
	return 0;
} 

