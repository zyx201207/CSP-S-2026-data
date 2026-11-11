#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s = "";
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a,c;
		cin >> a >> c;
		s.append(a,c);
	}
	int l = 0,r = s.size() - 1;
	int cnt = 0;
	while (l < r) cnt += (s[l++] != s[r--]);
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
