#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
pair<long long, char> s[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	long long len = 0;
	int tot = -1;
	for (int i = 1;i <= n;i++) {
		long long a;
		char ch;
		scanf("%lld %c", &a, &ch);
		if (tot != -1 && s[tot].second == ch) s[tot].first += a;
		else s[++tot] = {a, ch};
		len += a;
	}
	if (tot == 0) {
		printf("0");
		return 0;
	}
	int j = tot;
	long long jl = s[tot].first;
	long long l = 0;
	long long cnt = 0;
	for (int i = 0;i < tot;i++) {
		if (l >= len / 2ll) break;
		long long newl = min(s[i].first, len / 2ll - l);
		long long m = newl;
		//printf("%d %d %lld %lld %lld %lld\n", i, j, l, newl, jl, cnt);
		while (newl) {
			//printf("%c %c %lld %lld\n", s[i].second, s[j].second, newl, jl);
			if (newl >= jl) {
				newl -= jl;
				if (s[i].second != s[j].second) cnt += jl;
				j--;
				jl = s[j].first;
			} else {
				if (s[i].second != s[j].second) cnt += newl;
				jl -= newl;
				newl = 0;
			}
		}
		l += m;
	}
	printf("%lld", cnt);
	return 0;
}
