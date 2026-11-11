#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
int n;
long long m;
long long a[maxn];
long long cf[maxn];
long long v[maxn * 4];
long long tag[maxn * 4];
void push_down (int o, int l, int r){
	int mid = (l + r >> 1);
	if (tag[o]){
		tag[o * 2] += tag[o];
		tag[o * 2 + 1] += tag[o];
		v[o * 2] += tag[o] * (mid - l + 1);
		v[o * 2 + 1] += tag[o] * (r - mid);
		tag[o] = 0;
	}
}
void update (int o, int l, int r, int ul, int ur, long long val){
	if (ul <= l && r <= ur){
		v[o] += val * (long long)(r - l + 1);
		tag[o] += val;
		return;
	}
	push_down (o, l, r);
	int mid = (l + r >> 1);
	if (ul <= mid){
		update (o * 2, l, mid, ul, ur, val);
	}
	if (mid < ur){
		update (o * 2 + 1, mid + 1, r, ul, ur, val);
	}
	v[o] = v[o * 2] + v[o * 2 + 1];
}
long long query (int o, int l, int r, int ql, int qr){
	if (ql <= l && r <= qr){
		return v[o];
	}
	push_down (o, l, r);
	int mid = (l + r >> 1);
	long long ret = 0;
	if (ql <= mid){
		ret += query (o * 2, l, mid, ql, qr);
	}
	if (mid < qr){
		ret += query (o * 2 + 1, mid + 1, r, ql, qr);
	}
	v[o] = v[o * 2] + v[o * 2 + 1];
	return ret;
}
int main () {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	ios::sync_with_stdio (false);
	cin.tie (0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort (a + 1, a + n + 1);
	int ans = 1;
	int lst = 1;
	for (int i = 2; i <= n; i++){
		int l = lst, r = i - 1;
		while (r - l > 1){
			int mid = (l + r >> 1);
			if (query (1, 1, n, mid, i - 1) + (a[i] - a[i - 1]) * (i - mid) <= m){
				r = mid;
			}
			else{
				l = mid;
			}
		}
//		cout << "End with " << l << " " << r << " # " << a[i] - a[i - 1] << endl;
		if (query (1, 1, n, l, i - 1) + (a[i] - a[i - 1]) * (i - l) <= m){
//			cout << "Into " << l << " " << query (1, 1, n, l, i - 1) << endl;
			ans = max (ans, i - l + 1);
			lst = l;
			update (1, 1, n, l, i - 1, a[i] - a[i - 1]);
		}
		else if (query (1, 1, n, r, i - 1) + (a[i] - a[i - 1]) * (i - r) <= m){
//			cout << "Into " << r << " " << query (1, 1, n, r, i - 1) << endl;
			ans = max (ans, i - r + 1);
			lst = r;
			update (1, 1, n, r, i - 1, a[i] - a[i - 1]);
		}
		else{
//			cout << "Null" << endl;
			lst = i;
		}
	}
	cout << ans;
	cout << flush;
	fclose (stdin);
	fclose (stdout);
	return 0;
}
