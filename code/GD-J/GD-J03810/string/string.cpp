#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct P {
	int cnt;
	char c;
};

long long solve(const vector<P> &s, long long len) {
	long long ans = 0;
	
	const long long mid = len / 2;
	int lfti = 0, rhti = s.size() - 1;
	long long lenl = 0, lenr = 0;
	
	int lftn = s[lfti].cnt;
	char lftc = s[lfti].c;
	lenl += lftn;
	if (lenl - mid > 0) {
		lftn -= lenl - mid;
		lenl = mid;
	}
	
	int rhtn = s[rhti].cnt;
	char rhtc = s[rhti].c;
	lenr += rhtn;
	if (lenr - mid > 0) {
		rhtn -= lenr - mid;
		lenr = mid;
	}
	
	while (lfti <= rhti) {
		if (lftn > rhtn) {
			if (rhtc != lftc) {
				ans += rhtn;
			}
			lftn -= rhtn;
			rhti--;
			rhtn = s[rhti].cnt;
			rhtc = s[rhti].c;
			lenr += rhtn;
			if (lenr - mid > 0) {
				rhtn -= lenr - mid;
				lenr = mid;
			}
		} else if (rhtn > lftn) {
			if (rhtc != lftc) {
				ans += lftn;
			}
			rhtn -= lftn;
			lfti++;
			lftn = s[lfti].cnt;
			lftc = s[lfti].c;
			lenl += lftn;
			if (lenl - mid > 0) {
				lftn -= lenl - mid;
				lenl = mid;
			}
		} else {
			if (rhtc != lftc) {
				ans += rhtn;
			}
			lfti++;
			rhti--;
			lftn = s[lfti].cnt;
			lftc = s[lfti].c;
			lenl += lftn;
			if (lenl - mid > 0) {
				lftn -= lenl - mid;
				lenl = mid;
			}
			
			rhtn = s[rhti].cnt;
			rhtc = s[rhti].c;
			lenr += rhtn;
			if (lenr - mid > 0) {
				rhtn -= lenr - mid;
				lenr = mid;
			}
		}
	}
	return ans;
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	long long len = 0;
	vector<P> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i].cnt >> s[i].c;
		len += s[i].cnt;
	}
	if (s.size() == 1) {
		cout << 0 << endl;
		return 0;
	}
	
	const long long ans1 = solve(s, len);
	reverse(s.begin(), s.end());
	const long long ans2 = solve(s, len);
	cout << min(ans1, ans2) << endl;
}
