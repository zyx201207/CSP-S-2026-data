#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 10;
int n, m1;
ll nums, num, cnt, sum[N];
struct node{
	int a;
	char c;
}s[N];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i].a >> s[i].c;
		nums += s[i].a;
	}
	if (nums % 2 == 0) {
		num /= 2;
	} else {
		num = num / 2 + 1;
	}
	sum[1] = s[1].a;
	for (int i = 2; i <= n; i++) {
		sum[i] = sum[i - 1] + s[i].a;
		if (sum[i] >= num) {
			m1 = i;
			ll k1 = sum[i] - num;
			ll k2 = num - sum[i];
			if (k1 > k2) {
				s[i].a = s[i].a - 2 * k2;
			} else {
				s[i].a = s[i].a - 2 * k1;
			}
		}
	}
	ll l = 1, r = n;
	while(s[m1].a > 0) {
		if (s[l].c != s[r].c) {
			if (s[l].a > s[r].a) {
				cnt += s[r].a;
				r--;
				s[l].a -= s[r].a;
			} else if (s[l].a < s[r].a) {
				cnt += s[l].a;
				l++;
				s[r].a -= s[l].a;
			}
			else {
				l++;
				r++;
				cnt += s[l].a;
			}
		} if (s[l].c == s[r].c) {
			if (s[l].a > s[r].a) {
				r--;
				s[l].a -= s[r].a;
			} else if (s[l].a < s[r].a) {
				l++;
				s[r].a -= s[l].a;
			}
			else {
				l++;
				r++;
			}
		}
	}
	cout << cnt << '\n';
	return 0;
}
