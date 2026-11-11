#include <bits/stdc++.h>
using namespace std;
#define int long long

int c,T;
long long n,d,a[2000005];
int dpd[2000005],dpf[305][305];
int tr[800005];

int lc(int rt) {
	return rt * 2;
}

int rc(int rt) {
	return lc(rt) + 1;
}

void pushup(int rt) {
	tr[rt] = min(tr[lc(rt)],tr[rc(rt)]);
}

void build(int rt,int l,int r) {
	if (l == r) {
		tr[rt] = 1e9;
		return;
	}
	int mid = (l + r) >> 1;
	build(lc(rt),l,mid);
	build(rc(rt),mid + 1,r);
	pushup(rt);
}

void update(int rt,int l,int r,int p,int x) {
	if (l == p && r == p) {
		tr[rt] = x;
		return;
	}
	int mid = (l + r) >> 1;
	if (p <= mid) update(lc(rt),l,mid,p,x);
	else update(rc(rt),mid + 1,r,p,x);
	pushup(rt); 
}

int query(int rt,int l,int r,int ql,int qr) {
	
	if (ql <= l && r <= qr) {
		return tr[rt];
	}
	int res = 1e9;
	int mid = (l + r) >> 1;
	if (ql <= mid) res = min(res,query(lc(rt),l,mid,ql,qr));
	if (qr > mid) res = min(res,query(rc(rt),mid + 1,r,ql,qr));
	return res;
}

signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> c >> T;
	while (T--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		if (c <= 6) {
			int cnt = 0;
			for (int l = 1; l <= n; l++) {
				
				build(1,1,n);
				update(1,1,n,l,0);
				for (int r = l + 1; r <= n; r++) {
					int pos = lower_bound(a + l,a + r,a[r] - d) - a;
					dpd[r] = query(1,1,n,pos,r) + 1;
					update(1,1,n,r,dpd[r]);
				}
				
				for (int i = 1; i <= n; i++) {
					for (int j = 0; j <= n; j++) dpf[i][j] = 0;
				}
				dpf[l][0] = 1;
				for (int r = l + 1; r <= n; r++) {
					int pos = lower_bound(a + l,a + r,a[r] - d) - a;
					if (dpd[r] > n) continue;
					for (int i = 1; i <= dpd[r]; i++) {
						for (int j = pos; j < r; j++) {
								dpf[r][i] += dpf[j][i - 1];
						}
					}
					if (dpd[r] <= n && dpf[r][dpd[r]] == 2) {
						cnt++;
					}
				}
			}
			cout << cnt << "\n";
		} else if (c == 11 || c == 12) {
			long long c = a[2] - a[1];
			long long k = d / c;
			if (k <= 1 || n < 2 * k - 1) {
				cout << "0\n";
				continue;
			}
			cout << n - 2 * k + 1 << "\n";
			continue;
		}
		
	}
	return 0;
}
