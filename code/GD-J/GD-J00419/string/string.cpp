#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int n, a;
long long l, ans;
char c;
string s = "#";
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		scanf("%d %c", &a, &c), l += a;
		for(int j=1; j<=a; j++) s += c;
	} int mid = (l%2?l/2+1:l/2);
	for(int i=1; i<=mid; i++)
		if(s[i]!=s[l-i+1]) ans++;
	printf("%lld", ans);
	return 0;
}
