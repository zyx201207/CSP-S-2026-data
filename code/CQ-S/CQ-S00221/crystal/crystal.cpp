#include<iostream>
#include<vector>
#include<cassert>
#include<algorithm>
using namespace std;
int mian(); int main() { return mian(); }

#define ll long long
#define fi first
#define se second
#define ppt pair<int, int>
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define pb push_back

#define getchar getchar_unlocked
#define putchar putchar_unlocked
#define gch ch = getchar()
void read(int & x) { x = 0; char gch; while(!isdigit(ch)) gch; while(isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), gch; }
int stk_write[40], top_write;
void write(int x) {
	if(!x) return putchar('0'), void();
	if(x < 0) putchar('-'), x = -x;
	while(x) stk_write[++top_write] = x % 10, x /= 10;
	while(top_write) putchar('0' + stk_write[top_write]), top_write--;
}

const int N = 5e5 + 55;
int n, _;
ll m, a[N];
ll sum[N];

int mian() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	_ = scanf("%d%lld", &n, &m);
	FOR(i, 1, n) _ = scanf("%lld", &a[i]);
	sort(a + 1, a + 1 + n);
	FOR(i, 1, n) sum[i] = sum[i - 1] + a[i];
	int l = 0, ans = 1;
	FOR(i, 1, n) {
		while(l <= i and a[i] * (i - l + 1) - (sum[i] - sum[l - 1]) > m) l++;
		ans = max(ans, i - l + 1);
	}
	printf("%d\n", ans);
	return 0;
}