//GZ-S00003 贵阳市白云区华师一学校 殷浩然 
#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define upp(i, l, r) for(int i = l; i <= r; i++)
#define dww(i, l, r) for(int i = l; i >= r; i--)
#define PII pair<int, int>
#define ub push_back
#define x first
#define y second
using namespace std;

const int N = 5e5 + 5;

int n, m;
int a[N];
int s[N];

bool check(int mid, int i) {
	int p = a[i] * (i - mid + 1);
	int q = s[i] - s[mid - 1];
	return ((p - q) <= m);
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	upp(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	upp(i, 1, n) s[i] = s[i - 1] + a[i];
	int res = 0;
	upp(i, 1, n) {
		int l = 1, r = i;
		while(l < r) {
			int mid = (l + r) >> 1;
			if (check(mid, i)) r = mid;
			else l = mid + 1;
		}
		res = max(res, i - l + 1);
	}
	cout << res;
	
	return 0;
}
