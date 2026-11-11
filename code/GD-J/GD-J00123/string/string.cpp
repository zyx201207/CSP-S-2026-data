#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
struct node {
	int t;
	string s;
}a[200010];
struct node1 {
	int pos1, pos2;
};
int s[200010];
int ans;
signed main () {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin >> n;
	int L = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].t >> a[i].s;
		s[i] = s[i - 1] + a[i].t;
		L += a[i].t;
	}
	int L1, L2;
	L1 = L / 2;
	L2 = L1 + 1 + (L % 2);
	node1 temp, temp1;
	for (int i = 1; i <= L1; i++) {
		if (s[i] >= L1) {
			temp = {i, L1 - s[i - 1]};
			temp1 = {i, L1 - s[i - 1] + (L % 2) + 1};
			if (L1 - s[i - 1] + (L % 2) + 1 > a[i].t) {
				i += 1;
//				cout << L1 << " " << s[i - 1] << " " << a[i - 1].t << "\n";
				temp1 = {i, L1 - s[i - 2] + (L % 2) + 1 - a[i - 1].t};
			}
			if (L1 - s[i - 1] + (L % 2) + 1 - a[i - 1].t > a[i].t) {
				i += 1;
				temp1 = {i, L1 - s[i - 1] + (L % 2) + 1 - a[i - 1].t};
			}
			break;
		}
	}
//	cout << temp.pos1 << " " << temp.pos2 << " " << temp1.pos1 << " " << temp1.pos2 << "\n";
	for (int i = 1, j = n; i <= temp.pos1, j >= temp1.pos1; ) {
		if (i == temp.pos1)
			a[i].t = temp.pos2;
		if (j == temp1.pos1)
			a[j].t = a[j].t - temp1.pos2 + 1;
		if (a[i].s == a[j].s) {
			ans += abs(a[i].t - a[j].t);
		}
		else {
			ans += min(a[j].t, a[i].t);
		}
		if (a[i].t > a[j].t) {
				a[i].t -= a[j].t;
				j--;
			}
		else if (a[i].t < a[j].t) {
			a[j].t -= a[i].t;
			i++;
		}
		else i++, j--;
	}
	cout << ans;
	return 0;
} 

