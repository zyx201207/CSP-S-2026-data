#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef __int128_t i128;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<i128, int> pi128i;

constexpr int N = 2e6 + 10;
constexpr int iinf = 2e9;
constexpr ll linf = 2e18;

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
		writer &operator<< (const char ch) {
			putchar(ch);
			return *this;
		}
		writer &operator<< (const char str[]) {
			static int len;
			len = strlen(str);
			for (int i = 0; i < len; i++)
				putchar(str[i]);
			return *this;
		}
	} cout;
	const char endl = '\n';
}

#define cin fast_io::cin
#define cout fast_io::cout
#define endl fast_io::endl

int n;
ll d, x[N];
int lt[N], rt[N];

int cnt[N];

ll dis[N];
bool vis[N];
priority_queue<pli, vector<pli>, greater<pli>> pq;
void dij(const int pos) {
	fill(dis+pos, dis+n+1, linf);
	fill(vis+pos, vis+n+1, false);
	fill(cnt+pos, cnt+n+1, 0);
	pq.push({0, pos});
	
	ll pre, dist;
	int p, r;
	while (!pq.empty()) {
		pre = pq.top().first;
		p = pq.top().second;
		pq.pop();
		
		if (vis[p]) {
			if (pre == dis[p])
				cnt[p]++;
			continue;
		}
		vis[p] = true;
		cnt[p] = 1;
		
		for (r = p + 1; r <= rt[p]; r++) {
			if (vis[r])
				continue;
			dist = pre + x[r] - x[p];
			if (dist <= dis[r]) {
				dis[r] = dist;
				pq.push({dist, r});
			}
		}
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int c, t;
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
//		cerr <<"n: "<< n <<" d: "<< d <<'\n';
//		cerr <<"x: ";
//		for (int i = 1; i <= n; i++) {
//			cerr << x[i] <<' ';
//		}
//		cerr <<'\n';
		
		// 对于每一个点，寻找最后点与最前点 
		int l = 1, r = 1;
		i128 cur;
		for (int i = 1; i <= n; i++) {
			cur = x[i];
			while (cur - x[l] > d) {
//				cout <<"l: "<< cur <<" - "<< x[l] <<" = "<< cur - x[l] <<'\n';
				l++;
			}
			while (r < n && x[r+1] - cur <= d) {
//				cout <<"r: "<< x[r+1] <<" - "<< cur <<" = "<< x[r+1] - cur <<'\n';
				r++;
			}
			lt[i] = l;
			rt[i] = r;
		}
		
//		cout <<"lt: ";
//		for (int i = 1; i <= n; i++) cout << lt[i] <<' ';
//		cout <<'\n';
//		cout <<"rt: ";
//		for (int i = 1; i <= n; i++) cout << rt[i] <<' ';
//		cout <<'\n';
		
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			cur = rt[i];
			r = rt[cur];
			
			if (cur == i || cur == r)
				continue;
			
			while (r > cur && lt[r] == cur) r--;
			l = r;
			while (l > cur && lt[l] >= cur - 1) l--;
			ans += r - l;
			
//			cout << i <<" : "<< r - l <<" l: "<< l <<" r: "<< r <<'\n';
		}
		cout << ans <<'\n';
//		cerr << ans <<'\n'<<'\n';
		
		/*
		// 何不食肉糜？ 
		int r = 1;
		ll cur;
		for (int i = 1; i <= n; i++) {
			cur = x[i];
			while (r < n && x[r+1] - cur <= d)
				r++;
			rt[i] = r;
		}
		cerr <<"rt: ";
		for (int i = 1; i <= n; i++) cerr << rt[i] <<' ';
		cerr <<'\n';
		
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			dij(i);
			for (int j = i + 1; j <= n; j++) {
				if (cnt[j] == 2)
					ans++;
			}
			cerr <<"cnt: ";
			for (int j = i + 1; j <= n; j++) cerr << cnt[j] <<' ';
			cerr <<'\n';
		}
		
		cout << ans <<'\n';
		cerr << ans <<'\n'<<'\n';
		*/
	}
	
	return 0;
}
