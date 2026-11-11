#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5e5 + 10;
int n, cnt[N], ans;
char a[N];

signed main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> cnt[i] >> a[i]; 
	for(int i = 1, j = n; i < j; i++) {
		while(cnt[i] && i < j) {
			int sum = min(cnt[i], cnt[j]);
			if(a[i] != a[j]) ans += sum;
			cnt[i] -= sum;
			cnt[j] -= sum;
			while(!cnt[j] && j > i) j--;
		}
	} cout << ans;
	return 0;
} // fc string.out string.ans
