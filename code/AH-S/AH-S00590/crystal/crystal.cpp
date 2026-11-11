#include <bits/stdc++.h>
#define int long long
namespace IO {
	#define gc getchar_unlocked
	#define pc putchar_unlocked
	#define isdigit(ch) (ch >= '0' && ch <= '9')
	inline int read() {
		bool f = 0;
		char ch = gc();
		while (!isdigit(ch)) {
			if (ch == '-') f = 1;
			ch = gc();
		}
		
		int x = 0;
		while (isdigit(ch)) {
			x = (x << 1) + (x << 3) + (ch ^ 48);
			ch = gc();
		}
		
		if (f) return -x;
		return x;
	}
	inline void read(int &a) {a = read();}
	inline void read(int &a, int &b) {a = read(); b = read();}
	inline void read(int &a, int &b, int &c) {a = read(); b = read(); c = read();}
	
	void write(int x) {
		if (x < 0) {
			pc('-');
			x = -x;
		}
		if (x > 9) write(x / 10);
		pc(x % 10 + 48);
	}
}

using namespace IO;
using namespace std;
const int N = 5e5 + 10;

int a[N], n, m;
int sum[N];

inline int calc(int l, int r) {
	return (r - l) * a[r] - (sum[r - 1] - sum[l - 1]); 
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	read(n, m);
	for (int i = 1; i <= n; i++) {
		read(a[i]);
	}
	
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	
	//~ for (int i = 1; i <= n; i++) {
		//~ write(calc(1, i)); pc(' ');
	//~ }
	
	int l = 1, r = 0, ans = 1;
	while (r <= n) {
		r++;
		while (l <= r + 1 && calc(l, r) > m) l++;
		ans = max(ans, r - l + 1);
	}
	
	write(ans);
	return 0;
}
