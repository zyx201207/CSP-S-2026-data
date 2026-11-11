#include <bits/stdc++.h>
#define int long long

struct node {
	int cnt;
	char ch;
} blk[200010], fr[200010], bk[200010];

int N, l;

signed main() {
	freopen("string.in", "r", stdin), freopen("string.out", "w", stdout);
	std::cin >> N;
	for (int i = 1; i <= N; i ++) std::cin >> blk[i].cnt >> blk[i].ch, l += blk[i].cnt;
	l /= 2;
	int s1 = 0, s2 = 0, cnt1 = 0, cnt2 = 0;
	for (int i = 1; i <= N; i ++) {
		if (s1 + blk[i].cnt <= l) s1 += blk[i].cnt, fr[++ cnt1] = blk[i];
		else if (s1 < l) fr[++ cnt1] = {l - s1, blk[i].ch}, s1 = l;
		else break;
	}
	for (int i = (cnt2 = 0, N); i >= 1; i --) {
		if (s2 + blk[i].cnt <= l) s2 += blk[i].cnt, bk[++ cnt2] = blk[i];
		else if (s2 < l) bk[++ cnt2] = {l - s2, blk[i].ch}, s2 = l;
		else break;
	}
	
	int ans = 0, id1 = 1, id2 = 1;
	for (int now = 0; now < l; ) {
		int mn = std::min(fr[id1].cnt, bk[id2].cnt);
		now += mn;
		if (fr[id1].ch != bk[id2].ch) ans += mn;
		
		if (fr[id1].cnt == bk[id2].cnt) id1 ++, id2 ++;
		else if (fr[id1].cnt > bk[id2].cnt) fr[id1].cnt -= bk[id2].cnt, id2 ++;
		else bk[id2].cnt -= fr[id1].cnt, id1 ++; 
	}
	
	std::cout << ans;
	return 0;
}
