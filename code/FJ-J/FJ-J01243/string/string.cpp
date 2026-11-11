#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n, a;
char c;
string s = "";
int len = 0, ans = 0;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%1s", &a, &c);
		for (; a--; ) {
			s += c;
		}
	}
	len = s.size();
	for (int i = 0, j = len - 1; i < j; i++, j--) {
		if (s[i] != s[j])
			++ans;
	}
	printf("%d\n", ans);
	return 0;
}

/*
68pts
*/
