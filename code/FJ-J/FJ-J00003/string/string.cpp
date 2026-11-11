#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,char> PIC;

const int N = 2e5+7, INF = 0x3f3f3f3f, M = 2e5+7;

PIC a[N], b[N];
 
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		char c;
		cin >> x >> c; // AC!!
		sum += x;
		a[i] = {x, c};
	}
	int tot = 0;
	bool isodd = sum & 1;
	sum = sum / 2 + (sum & 1);
	ll cnt = 0;
	int mid = 0;
	for (int i = 1; i <= n; i++) {
		cnt += a[i].first;
		
		if (cnt < sum || mid) b[++tot] = a[i];
		else if (cnt == sum && !(sum & 1)) b[++tot] = a[i], b[++tot] = {0, '#'}, mid = tot;
		else if (cnt >= sum && !mid) {
			int k = sum - cnt + a[i].fi - isodd;
			if (k > 0) b[++tot] = {k, a[i].se};
			b[++tot] = {0, '#'};
			mid = tot;
//			b[++tot] = {sum - cnt + a[i-1].fi, a[i].se};
			b[++tot] = {cnt - sum, a[i].se};
//			flag = 1;
		}
//		printf("i = %d, sum = %lld, cnt = %lld, mid = %d\n", i, sum, cnt, mid);
	}
	ll s1 = 0, s2 = 0;
//	for (int i = 1; i <= tot; i++) {
//		cout << b[i].first << " " << b[i].se << '\n';
//	}
//	for (int i = 1; i < mid; i++) s1 += b[i].fi;
//	for (int i = mid+1; i <= tot; i++) s2 += b[i].fi;
//	cout << s1 << " " << s2 << endl;
	ll ans = 0;
	int i = 1, j = tot;
	ll cnt1 = b[i].fi, cnt2 = b[j].fi;
	char c1 = b[i].se, c2 = b[j].se;
//	printf("i=%d j=%d cnt1=%lld cnt2=%lld c1=%c c2=%c ans=%lld\n", i, j, cnt1, cnt2, c1, c2, ans);
	while (i < mid && j > mid) {
//		cout << c1 << c2 << endl;
		if (c1 == c2) {
			if (cnt1 < cnt2) {
				cnt2 -= cnt1;
				cnt1 = 0;
				i++;
				cnt1 = b[i].fi;
			}
			else if (cnt1 > cnt2){
				cnt1 -= cnt2;
				cnt2 = 0;
				j--;
				cnt2 = b[j].fi;
			}
			else {
				i++, j--;
				cnt1 = b[i].fi, cnt2 = b[j].fi;
//				cout << -1 << endl;
			}
		}
		else {
			if (cnt1 < cnt2) {
				cnt2 -= cnt1;
				ans += cnt1;
				cnt1 = 0;
				i++;
				cnt1 = b[i].fi;
			}
			else if (cnt1 > cnt2) {
				cnt1 -= cnt2;
				ans += cnt2;
				cnt2 = 0;
				j--;
				cnt2 = b[j].fi;
			}
			else {
				i++, j--;
				ans += cnt1;
				cnt1 = b[i].fi, cnt2 = b[j].fi;
//				cout << -2 << endl;
			}
		}
		c1 = b[i].se, c2 = b[j].se;
//		printf("i=%d j=%d cnt1=%lld cnt2=%lld c1=%c c2=%c ans=%lld\n", i, j, cnt1, cnt2, c1, c2, ans);
	}
	cout << ans << '\n';
	
	
	return 0;
}
