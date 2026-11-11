#include <iostream>
#include <algorithm>
using namespace std;

const int M = 8e5;
int n, m, maxn; 
string s[M], ans[M];
bool k[M];

string f(long long x) {
	string ret = "";
	while (x > 0) {
		ret = char(x % 2 + '0') + ret;
		x >>= 1;
	}
	maxn = max(maxn, int(ret.size()));
	return ret;
}

bool cmp(string a, string b) {
	if (a.size() > b.size()) return true;
	else if (a.size() == b.size()) return a > b;
	else return false;	
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		long long t;
		cin >> t;
		s[i] = f(t);
	}
	sort(s + 1, s + n + 1, cmp); 
	
	for (int i = 0; i < maxn; i++) {
		int num = 0;
		for (int j = 1; j <= n; j++) {
			if (k[j]) continue;
			if (s[j].size() >= maxn - i and s[j][i - (maxn - s[j].size())] == '1') num++;
		}
		if (num >= m) {
			for (int j = 1; j <= n; j++) {
				if (k[j]) continue;
				if (s[j].size() < maxn - i or s[j][i - (maxn - s[j].size())] == '0') k[j] = true;
			}
		}
		if(num == m) break;
	}
	
	int len = 0;
	maxn = 0;
	for (int i = 1; i <= n; i++) {
		if (k[i]) continue;
		ans[++len] = s[i];
		maxn = max(maxn, int(s[i].size()));
		if (len >= m) break;
	}
	
	string q = "";
	for (int i = 0; i < maxn; i++) {
		bool flag = true;
		for (int j = 1; j <= len; j++) {
			if (ans[j].size() < maxn - i or ans[j][i - (maxn - ans[j].size())] == '0') {
				flag = false;
				break;
			}
		}
		q += char(flag + '0');
	}
	
	long long qq = 0, t = 1;
	for (int i = q.length() - 1; i >= 0; i--) {
		qq += t * (q[i] - '0');
		t *= 2;
	}
	cout << qq;
	return 0;
}
