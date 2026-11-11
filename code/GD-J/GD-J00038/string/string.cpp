#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int N = 2e5 + 10;
int n, a[N], b[N], id;
char c[N]; 
long long ans, s[N], s2[N];
vector <long long> v, p;
unordered_map <long long, bool> mp;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i] >> c[i];
		b[n - i + 1] = a[i];
	}
	for (int i = 1; i <= n; i ++) s[i] = s[i - 1] + a[i], s2[i] = s2[i - 1] + b[i];
	
	long long t = 1;
	for (int i = 1; i <= n; i ++) {
		v.push_back(t);
		t += a[i];
	}
	t = 0;
	for (int i = 1; i <= n; i ++) {
		t += a[i];
		v.push_back(t);
	}
	t = 1;
	for (int i = n; i >= 1; i --) {
		v.push_back(t);
		t += a[i];
	}
	t = 0;
	for (int i = n; i >= 1; i --) {
		t += a[i];
		v.push_back(t);
	}
	
	sort(v.begin(), v.end());
	for (long long num : v)
		if (!mp[num]) {
			mp[num] = true;
			p.push_back(num);
		}
		
	p.push_back(s[n] + 1);
	for (int i = 0; i < (int)p.size() - 1; i ++) {
		int pos1 = lower_bound(s + 1, s + n + 1, p[i]) - s;
		int pos2 = lower_bound(s2 + 1, s2 + n + 1, p[i]) - s2;
		ans += (p[i + 1] - p[i]) * (c[pos1] != c[n - pos2 + 1]);
	}
	cout << ans / 2 << '\n';
	
	return 0;
}

