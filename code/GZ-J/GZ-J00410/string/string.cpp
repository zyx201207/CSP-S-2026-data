//GZ-J00410 肖耿毅 兴义市弘毅中学
#include<bits/stdc++.h>
using namespace std;
long long n, ans, length;
int str[10000050];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%lld", &n);
	long long tmp;
	char c;
	for(int i = 1; i <= n; i++) {
		scanf("%lld %c", &tmp, &c);
		for(int i = 1; i <= tmp; i++) {
			str[i + length] = c - 'a';
		}
		length += tmp;
	}
	long long mid = (length + 1) / 2;
	for(int i = 1; i <= mid; i++) {
		if(str[i] != str[length - i + 1]) ans++;
	}
	printf("%lld\n", ans);
	return 0;
}
