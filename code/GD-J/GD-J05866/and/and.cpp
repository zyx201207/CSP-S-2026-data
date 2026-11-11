#include<bits/stdc++.h>
using namespace std;

bool able[31];
bool n_able[200005][31];
bool ignored[200005];
int n, m;
int max_2 = 0;

string get_ten_2_2(int n) {
	string s = "";
	while (n > 1) {
		s += to_string(n % 2);
		n /= 2;
	}
	s += to_string(n);
	return s;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		string s = get_ten_2_2(a);
		// cout << a << ":" << s << endl;
		int s_len = s.size();
		max_2 = max(max_2, s_len);
		for (int i2 = 0; i2 < s_len; i2++) {
			n_able[i][i2] = (s[i2] == '1');
		}
	}
	
	for (int i = max_2 - 1; i >= 0; i--) {
		int x = 0;
		for (int i2 = 0; i2 < n; i2++) {
			if (!ignored[i2] && n_able[i2][i]) x++;
		}

		if (x >= m) {
			for (int i2 = 0; i2 < n; i2++) {
				if (!n_able[i2][i]) ignored[i2] = true;
			}
			able[i] = true;
		}
	}

	int ans = 0;
	for (int i = max_2 - 1; i >= 0; i--) {
		if (able[i]) ans += pow(2, i);
	}

	cout << ans;
	
	return 0;
} 
