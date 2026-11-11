//luogu uid: 1063589
#include <bits/stdc++.h>

//多测记得清空
//记得 long long 

//吓死我了我还以为 18:00结束 
//没做完呜呜 

typedef long long ll;

const int N = 2e6 + 5;

using namespace std;

int c, t, n, lpos[N], rpos[N], dpl[N], dpr[N];
ll d, a[N], cntl[N], cntr[N];

void solve() {
	scanf("%d %lld", &n, &d);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	
	for (int l = 1, r = 1; r <= n; r++) {
		while (a[r] - a[l] > d)
			l++;
		//a[r] - a[l] <= d
		lpos[r] = l;
//		printf("lpos[%d] = %d\n", r, l);
	}
	
	for (int l = n, r = n; l; l--) {
		while (a[r] - a[l] > d)
			r--;
		rpos[l] = r;
//		printf("rpos[%d] = %d\n", l, r);
	}
	
	for (int r = 1; r <= n; r++) {
		int l = lpos[r];
		dpl[r] = 1;
		if (l != r && (lpos[l] == 1 || rpos[lpos[l]] == l))
			dpl[r] += dpl[l];
//		printf("dpl[%d] = %d\n", r, dpl[r]);
	}
	
	for (int l = n; l; l--) {
		int r = rpos[l];
		dpr[l] = 1;
		if (l != r && (rpos[r] == n || lpos[rpos[r]] == r))
			dpr[l] += dpr[r];
//		printf("dpr[%d] = %d\n", l, dpr[l]);
	}
	
	for (int i = 2; i < n; i++)
		cntl[i] = cntr[i] = 0;
	
	for (int l = 1; l <= n; l++) {
		if (rpos[l] - l > 1 && lpos[rpos[l]] == l) {
			cntl[rpos[l]] += dpl[l];
//			printf("l = %d, cntl[%d]++\n", l, rpos[l]);
		}
	}
	
	for (int r = n; r; r--) {
		if (r - lpos[r] > 1 && rpos[lpos[r]] == r) {
			cntr[lpos[r]] += dpr[r];
//			printf("r = %d, cntr[%d]++\n", r, lpos[r]);
		}
	}
	
	ll res = 0;
	for (int mid = 2; mid + 1 < n; mid++) {
		res += (ll)cntl[mid + 1] * cntr[mid];
//		res += (ll)(rpos[lpos[mid + 1]] == mid + 1 ? cntl[mid + 1] : 1) * (lpos[rpos[mid]] == mid ? cntr[mid] : 1);
//		printf("mid = %d, %lld * %lld\n", mid, cntl[mid + 1], cntr[mid]);
//		int l = lpos[mid + 1], r = rpos[mid];
//		//漏算了 一段区间 
////		printf("l = %d, mid = %d, r = %d, %d * %d\n", l, mid, r, dpl[l], dpr[r]);
//		if (rpos[l] != mid + 1 || lpos[r] != mid)
//			continue;
//		
//		if (l < mid && mid + 1 < r)
//			res += (ll)dpl[l] * dpr[r];
//		
	}
	
	printf("%lld\n", res);
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	scanf("%d %d", &c, &t);
	
	while (t--)
		solve();
	
	return 0;
}
