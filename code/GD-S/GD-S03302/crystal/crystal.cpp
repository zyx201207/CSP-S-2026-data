#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

constexpr int N = 5e5 + 10;
constexpr ll inf = 1e18;

namespace fast_io {
	struct reader {
		template <typename T> reader &operator>> (T &x) {
			static int f;
			static char ch;
			x = 0;
			f = 1;
			ch = getchar();
			while (!isdigit(ch)) {
				if (ch == '-')
					f = -1;
				ch = getchar();
			}
			while (isdigit(ch)) {
				x = x * 10 + ch - '0';
				ch = getchar();
			}
			x *= f;
			return *this;
		}
	} cin;
	struct writer {
		static const int SIZE = 60;
		template <typename T> writer &operator<< (T x) {
			static char str[60];
			static int cnt;
			
			if (x == 0) {
				putchar('0');
				return *this;
			}
			if (x < 0) {
				x = -x;
				putchar('-');
			}
			
			cnt = 0;
			while (x) {
				str[cnt++] = x % 10 + '0';
				x /= 10;
			}
			while (cnt) {
				putchar(str[--cnt]);
			}
			return *this;
		}
		writer &operator<< (char ch) {
			putchar(ch);
			return *this;
		}
	} cout;
	const char endl = '\n';
}

#define cin fast_io::cin
#define cout fast_io::cout
#define endl fast_io::endl

int n;
ll m, a[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	
	// 滑动窗口 
	int l = 1, ans = 1;// 只选第一个是肯定可以的 
	ll sum = m;
	for (int r = 2; r <= n; r++) {
		sum -= (r - l) * (a[r] - a[r-1]);
		while (sum < 0) sum += a[r] - a[l++];
		ans = max(ans, r - l + 1);
//		cerr << l <<' '<< r <<" sum: "<< sum <<'\n';
	}
	cout << ans;
	return 0;
}
