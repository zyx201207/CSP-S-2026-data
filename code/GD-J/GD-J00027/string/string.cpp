#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
const int N = 2e5 + 10;
int n;
struct node {
	int len;
	char c;
} arr[N];
ll cnt = 0;
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	rep(i, 1, n) {
		cin >> arr[i].len >> arr[i].c;
	}
	ll lp = 1, rp = n;
	node l = arr[1], r = arr[n];
	while(lp < rp) {
		int ll = l.len, rl = r.len;
		if(ll > rl) {
			if(l.c != r.c) cnt += rl;
			l.len = ll - rl;
			r = arr[--rp];
		}
		else if(ll == rl) {
			if(l.c != r.c) cnt += ll;
			l = arr[++lp], r = arr[--rp];
		}
		else if(ll < rl) {
			if(l.c != r.c) cnt += ll;
			r.len = rl - ll;
			l = arr[++lp];
		}
	}
	cout << cnt << endl;
	return 0;
}
