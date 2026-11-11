#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;

ifstream cin("crystal.in");
ofstream cout("crystal.out");

const int N = 5e5+5;
int n;
long long m;
long long a[N];
long long d[N];

int main() {
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	for(int i=1; i<=n; i++) {
		d[i] = a[i]-a[i-1];
	}
	/*for(int i=1; i<=n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	for(int i=1; i<=n; i++) {
		cout << d[i] << " ";
	}
	cout << endl;*/
	// long long mo = m;
	int u, v;
	u = 1;// sum [u,v)
	v = 2;
	int ans = 1;
	while(v <= n) {
		int l = v-u;
		// c: a (m-l*d[v] >= 0)
		if(m-l*d[v] >= 0) {
			m -= l*d[v];
			v++;
			ans = max(ans, v-u);
			continue;
		}
		// c: b (m-l*d[v] < 0)
		if(u == v-1) {
			u++;
			v++;
			continue;
		} else {
			m += a[v-1] - a[u];
			u++;
			continue;
		}
	}
	cout << ans << endl;
	return 0;
}
