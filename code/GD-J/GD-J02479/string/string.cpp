#include <bits/stdc++.h>
using namespace std;

string str = "";
long long cnt = 0, n, t;
char c;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> t >> c;
		str += string(t, c);
	}
	for(int i = 0;i < str.size() / 2;i++) {
		if(str[i] != str[str.size() - i - 1]) {
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}
