#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

constexpr int N = 114514 + 10;
constexpr int inf = 1e9;

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

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	cout << (ll)1145141919810;
	
	return 0;
}
