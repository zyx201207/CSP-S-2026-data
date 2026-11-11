#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5E5+5; 
int n, m, a[MAXN];
int near_one, near_two; 
int cnt[MAXN];
int ans[MAXN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
//	freopen("card.in", "r", stdin);
//	freopen("card.out", "w", stdout);
	
	near_one = 0x3f3f3f3f, near_two = 0x3f3f3f3f;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		cnt[a[i]] ++;
		if (a[i] == 1)  near_one = min(near_one, i);
		else if (a[i] == 2)   near_two = min(near_two, i);
	}
	if (m <= 2) {
		for (int i = 1; i <= n; i ++) {
			if (i > 2) {
				ans[1] ++;
				ans[2] ++;
				continue;
			}
		}
		int cnt11 = 0, cnt21 = 0, cnt12 = 0, cnt22 = 0;
		for (int i = 1; i <= near_one; i ++) {
			if (a[i] == 1)    cnt11 ++;
			else   cnt21 ++; 
		}
		for (int i = 1; i <= near_two; i ++) {
			if (a[i] == 1)    cnt12 ++;
			else   cnt22 ++;
		}
		int tt_cnt1 = cnt12 + ans[1];
		int tt_cnt2  = cnt21 + ans[2];
		cout << tt_cnt1 << " " << tt_cnt2;
	}
	
	return 0; 
}
