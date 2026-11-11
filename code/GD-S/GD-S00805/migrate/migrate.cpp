#include<bits/stdc++.h>
using namespace std;

long long c, t, n, d;
long long a[2000006];
long long fx[2000005];
long long fy[2000005];
long long sum_fx[2000005];

//struct Node {
//	long long minn, sum;
//}tr[8000005];

//void push_up(long long x) {
//	tr[x].minn = min(tr[x << 1].minn, tr[x << 1 | 1].minn);
//	return ;
//}
//
//void update(long long x, long long c, long long l, long long r, long long rt) {
//	if (l == r) {
//		tr[rt].minn = c;
//		return ;
//	}
//	long long mid = (l + r) >> 1;
//	if (x <= mid) update(x, c, l, mid, rt << 1);
//	else update(x, c, mid + 1, r, rt << 1 | 1);
//	push_up(rt);
//	return ;
//}
//
//long long query_min(long long a, long long b, long long l, long long r, long long rt) {
//	if (a <= l && r <= b) {
//		return tr[rt].minn;
//	}
//	long long mid = (l + r) >> 1;
//	long long minn = 2e9;
//	if (a <= mid) minn = min(minn, query_min(a, b, l, mid, rt << 1));
//	if (mid < b) minn = min(minn, query_min(a, b, mid + 1, r, rt << 1));
//	return minn;
//}
//
//long long query_sum(long long a, long long b, long long c, long long l, long long r, long long rt) {
//	if (a <= l && r <= b && tr[rt].minn <= c) {
//		return r - l + 1;
//	}
//	long long mid = (l + r) >> 1;
//	long long sum = 0;
//	if (a <= mid) sum += query_sum(a, b, c, l, mid, rt << 1);
//	if (mid < b) sum += query_sum(a, b, c, mid + 1, r, rt << 1);
//	return sum;
//}

signed main() {
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (long long i = 1; i <= n; i++) {
			fx[i] = fy[i] = 0;
			cin >> a[i];
		} 
////		for (long long i = 1; i <= 4 * n; i++) tr[i].minn = tr[i].sum = 0;
//		for (long long i = 1; i <= n; i++) {
//			long long pos = lower_bound(a + 1, a + 1 + i - 1, a[i] - d) - a;
//			if (i == 1 || a[i-1] + d < a[i]) {
//				fx[i] = fy[i] = 1;
////				update(i, fy[i], 1, n, 1);
//				sum_fx[i] = 1;
//				continue;
//			}
//			
//			long long minn = fy[pos];
//			long long pos2 = upper_bound(fy + pos, fy + 1 + i - 1, minn) - fy - 1;
//			long long sum = sum_fx[pos2] - sum_fx[pos-1];
//			
////			long long minn = query_min(pos, i - 1, 1, n, 1);
////			long long sum = query_sum(pos, i - 1, minn, 1, n, 1);
//			cout << i << " : " << pos << "," << pos2 << " , " << minn << " , " << sum << endl;
//			
////			cout << i << " " << a[i] - d << "-----\n";
////			for (long long j = pos; j < i; j++) cout << j << " : " << f[j].x << " , " << f[j].y << endl;
////			cout << endl;
//			fx[i] = sum;
//			sum_fx[i] = sum_fx[i-1] + sum;
//			fy[i] = minn + 1;
//			cout << fx[i] << " " << fy[i] << endl;
////			update(i, fy[i], 1, n, 1);
//		}
//		long long ans = 0;
//		for (long long i = 1; i <= n; i++) {
//		 	if (fx[i] == 2) ++ans;
//		}
//		cout << ans << endl;
		long long ans = 0;
		for (long long i = 1; i <= n; i++) {
			long long pos = upper_bound(a + 1, a + 1 + n, a[i] + d) - a - 1;
			if (pos - i <= 1) continue;
			if (a[i] + d >= a[n]) break;
			long long ii = pos - 2;
			long long jj = pos - 1;
			long long pos2 = upper_bound(a + 1, a + 1 + n, a[ii] + d) - a;
			long long pos3 = upper_bound(a + 1, a + 1 + n, a[jj] + d) - a - 1;
//			cout << pos3 << " " << pos2 << endl;
			long long sum = pos3 - pos2 + 1;
			ans += sum;
		} 
		cout << ans << endl;
	}
	
	return 0;
} 
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6



*/
