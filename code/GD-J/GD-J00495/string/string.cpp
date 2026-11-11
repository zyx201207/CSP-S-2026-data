#include <bits/stdc++.h>
using namespace std;

long long n,m = 0;
string s;

int main () {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for (int i = 1;i <= n;i++) {
		long long a;
		char c;
		scanf("%lld%c",&a,&c);
		m += a;
		for (int j = 1;j <= a;j++) {
			s += c;
		}
	}
	long long l = s.size(),sum = 0;
	for (int i = 0;i < (l / 2);i++) {
		if (s[i] != s[l - i - 1]) {
			sum++;
		}
	}
	printf("%lld",sum);
	return 0; 
}
