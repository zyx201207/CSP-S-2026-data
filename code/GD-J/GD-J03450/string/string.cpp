#include<bits/stdc++.h>
using namespace std;

#define int long long

int n;
int f(int x, const vector<int>& pref) {
	int l = 1, r = n;
	while(l <= r) {
		int mid = (l + r) >> 1;
		int ll = pref[mid - 1] + 1;
		int rr = pref[mid];
		
		if(ll <= x && x <= rr) return mid;
		if(x > rr) l = mid + 1;
		if(x < ll) r = mid - 1;
	}
	return 0;
}

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	cin >> n;
	vector<pair<int, char>> ch(n + 1);
	vector<int> pref(n + 1, 0);
	for(int i = 1; i <= n; i++) cin >> ch[i].first >> ch[i].second, pref[i] = pref[i - 1] + ch[i].first;
	
	int cnt = pref[n];
	int left = cnt >> 1, right;
	if(cnt & 1) right = ((cnt + 1) >> 1) + 1;
	else right = (cnt + 2) >> 1; // ¸³Öµ
//	cout << left << ' ' << right << '\n';
	
	int it_left = f(left, pref);
	int it_right = f(right, pref);
//	cout << it_left;
	
	int already = 0;
	int ans = 0;
	
	while(1) {
		int siz1 = left - pref[it_left - 1], siz2 = pref[it_right] - right + 1;
		if(siz1 < siz2) {
			if(ch[it_left].second != ch[it_right].second) ans += siz1;
			left -= siz1;
			right += siz1;
			if(right > pref[n] || left == 0) break;
			it_left = f(left, pref), it_right = f(right, pref);
		} else {
			if(ch[it_right].second != ch[it_left].second) ans += siz2;
			left -= siz2, right += siz2;
			if(right > pref[n] || left == 0) break;
			it_left = f(left, pref), it_right = f(right, pref); 
		}
	}
	cout << ans;
	
	return 0;
}
