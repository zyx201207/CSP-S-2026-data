#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
struct node{
	int s, a[40];
}b[N];
struct tomb{
	int len, v;
}t[40];
int an[N];
int n, m, ans = 0;
bool cmp(tomb x, tomb y) {
	if (x.v != y.v)
		return x.v > y.v;
	return x .len > y.len;	
}
void work1(int x, int y) {
	int l = 0;
	while (1) {
		if (x == 0) break;
		b[y].a[++l] = x % 2;
		x = x / 2;
	}
	b[y].s = l;
}
void work2(int x) {
	int siz = b[x].s;
	for (int i = 30; i >= 1; i--) {
		if (an[i] == b[x].a[i])
			an[i] = b[x].a[i];
		else
			an[i] = 0;	 
	}
}
long long work3() {
	int k = 1;
	long long res = 0LL;
	for (int i = 30; i >= 1; i--) {
		res = res + an[i] * k * 1LL;
		k = k * 2;
	}
	return res;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	int mxx = 0;
	for (int i = 1, tmp; i <= n; i++) {
		cin >> tmp;
		work1(tmp, i);
		mxx = max(mxx, tmp);
	}
	for (int i = 1; i <= n; i++) {
		int e = b[i].s;
		t[e].len++; t[e].v = e;
	}
	memset(an, 1, sizeof(an));
	int kill = 0;
	while (1) {
		sort(t, t + 35, cmp);
		int mx = 0, id;
		for (int i = 1; i <= 35; i++) {
			if (t[i].len > mx) {
				mx = t[i].len;
				id = i;
			}
		}
		int ck = min(m, mx);
		for (int i = 1; i <= n; i++) {
			if (b[i].s == id) {
				work2(i);
				m--;
			}
		}
		if (m <= 0) {
			cout << work3() << "\n";
			return 0;
		}
		t[id].len = 0, t[id].v = 0;
		kill++;
		if (kill > 30) {
			if (work3() > mxx)
				cout << mxx << "\n";
			else	
				cout << work3() << "\n";
			return 0;
		}
	}
	return 0;
} 
