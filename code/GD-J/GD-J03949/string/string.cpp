#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 2e5 + 10;
struct Node {
	int num;char c;
}a[N];
int n,ans = 0;bool istwo = true;

signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> a[i].num >> a[i].c;
		if (a[i].num % 2 != 0) {
			istwo = !istwo;
		}
	}
	int l = 1,r = n,lnum = a[l].num,rnum = a[r].num;
	while (l < r) {
		if (lnum < rnum) {
			if (a[l].c != a[r].c) {
				ans += lnum,rnum -= lnum,l++,lnum = a[l].num;
			} else {
				rnum -= lnum,l++,lnum = a[l].num;
			}
		} else if (lnum > rnum) {
			if (a[l].c != a[r].c) {
				ans += rnum,lnum -= rnum,r--,rnum = a[r].num;
			} else {
				lnum -= rnum,r--,rnum = a[r].num;
			}
		} else if (lnum == rnum) {
			if (a[l].c != a[r].c) {
				ans += lnum;l++,r--;lnum = a[l].num,rnum = a[r].num;
			} else {
				l++,r--;lnum = a[l].num,rnum = a[r].num;
			}
		}
	}
	cout << ans << endl;
	return 0;
}