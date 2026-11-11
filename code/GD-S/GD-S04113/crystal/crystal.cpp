#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define FO(i, a, b) for(int i = (a); i <= (int)(b); ++i)
#define RP(i, a, b) for(int i = (a); i >= (int)(b); --i)
LL read() {
	LL s = 0, f = 1; char ch; while(isspace(ch=getchar()));
	while(ch == '-' || isdigit(ch)) ch == '-' ? (f=-1) : (s=s*10+ch-'0'), ch=getchar();
	return s*f;
}

namespace {
	
	const int N = 5e5 + 10;
	int n; LL m, a[N];
	void work() {
		n=read(), m=read();
		
		FO(i, 1, n) a[i]=read();
		sort(a+1, a+n+1);
		
		int cur = 1, res = 0, ans = 0;
		LL sum = 0;
		FO(i, 1, n) {
			sum += res * (a[i] - a[i-1]); ++res;
			while(sum > m) sum -= a[i] - a[cur++], --res;
						
			ans = max(ans, res);
		}
		printf("%d\n", ans);
	}
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	work();
	return 0;
}
