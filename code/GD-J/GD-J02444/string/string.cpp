#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int M = 8e5; 

struct Pos {
	int k;
	char c;
}p[M];

vector <Pos> a, b;

int n;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	long long len = 0;
	for (int i = 1; i <= n; i++) {
		cin >> p[i].k >> p[i].c;
		len += p[i].k;
	}
	long long h = (len >> 1) + 1, t = 0;
	bool fl = (((h - 1) << 1) == len), w = false;
	a.push_back({0, 0});
	b.push_back({0, 0});
	for (int i = 1; i <= n; i++) {
		t += p[i].k;
		if (t >= h and !w) {
			if (h - (t - p[i].k) - 1 > 0) a.push_back({h - p[i - 1].k - 1, p[i].c}); 
			if (fl) b.push_back({t - h + 1, p[i].c});
			else if (t - h > 0) b.push_back({t - h, p[i].c});
			w = true;
		} else {
			if (t < h) a.push_back(p[i]);
			else b.push_back(p[i]);
		}
	}
	
	int i = 1, j = b.size() - 1;
	Pos x = a[i], y = b[j];
	long long ans = 0;
	while (i < a.size() and j > 0) {
		if (x.c != y.c) ans += min(x.k, y.k);
		if (x.k == y.k) i++, j--, x = a[i], y = b[j];
		else if (x.k > y.k) x.k -= y.k, j--, y = b[j];
		else y.k -= x.k, i++, x = a[i];
	}
	
	cout << ans;
	return 0;
} 
