#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=(j);i<=(k);i++)
#define per(i,j,k) for(int i=(j);i>=(k);i--)
template<class T>bool ckmax(T &x,const T y){return (x<y?x=y,1:0);}
template<class T>bool ckmin(T &x,const T y){return (x>y?x=y,1:0);}
inline int read(){
	int f=1,w=0,ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) w=w*10+ch-'0';
	return f*w;
}
const int N = 5e5 + 10;
int n, m, a[N];
namespace Cs {
	bool b[N];
	int c[N];
	int ans[N];
	int stk[N], tt;
	void add(int r, int x) {
		if (b[x]) {
			int now;
			do {
				now = stk[tt--];
				b[now] = false;
				ans[now] += c[now] - r;
			} while (now != x);
		}
		if (!b[x]) b[x] = true, c[x] = r, stk[++tt] = x;
	}
	void print() {
		per(i, tt, 1) printf("%d ", stk[i]);
		puts("");
	}
	void work() {
		per(i, n, 1) {
			add(i, a[i]);
//			print();
		}
		if (tt) add(0, stk[1]);
		rep(i, 1, m) printf("%d ", ans[i]);
	}
}
namespace Ds {
	bool st[N];
	int ans[N];
	void check(int x) {
		vector<int> b;
		rep(i, 1, m) st[i] = false;
		rep(i, x, n) {
			if (st[a[i]]) {
				while (b.back() != a[i]) {
					st[b.back()] = false;
					b.pop_back();
				}
				b.pop_back();
			}
			b.push_back(a[i]);
			st[a[i]] = true;
		}
		for (auto i : b) ans[i]++;
	}
	void work() {
		rep(i, 1, n) {
			check(i);
		}
		rep(i, 1, m) printf("%d ", ans[i]);
	}
}
namespace As {
	int cnt[N];
	void work() {
		rep(i, 1, n) cnt[a[i]]++;
		int sum = 0;
		rep(i, 1, m) {
			sum += cnt[i];
			printf("%d ", sum);
		}
	}
}
namespace Bs {
	int ans[N], lst[N], cnt, c[N], f[N];
	bool st[N];
	void check(int x, int len) {
		vector<int> b;
		rep(i, 1, m) st[i] = false, lst[i] = 0;
		rep(i, x, len) {
			if (st[c[i]]) {
				while (b.back() != c[i]) {
					st[b.back()] = false;
					b.pop_back();
				}
				b.pop_back();
			}
			b.push_back(c[i]);
			st[c[i]] = true;
		}
		for (auto i : b) lst[i]++;
	}
	void work() {
		rep(i, 1, n) {
			if (a[i] != a[i - 1]) c[++cnt] = a[i];
		}
		int j = 1;
		rep(i, 1, cnt) {
			while (j <= n && a[j] == c[i]) j++, f[i]++;
		}
		rep(i, 1, cnt) {
			check(i, cnt);
			rep(j, 1, m) {
				ans[j] += lst[j] * f[i];
			}
		}
		rep(i, 1, m) {
			printf("%d ", ans[i]);
		}
	}
}
bool as = true;
int bs;
int main() {
//	freopen("card6.in", "r", stdin);
//	freopen("card6.out", "w", stdout);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	n = read(), m = read();
	rep(i, 1, n) a[i] = read(), as &= (a[i] >= a[i - 1]), bs += (a[i] != a[i - 1]);
	if (as) As::work();
	else if (max(1ll*bs*m,1ll * bs * (bs + 1) / 2) <= 100000000ll) Bs::work();
	else Cs::work();
	return 0;
}
