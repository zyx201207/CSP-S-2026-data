#include<bits/stdc++.h>
using namespace std;

const int N = 200010;
long long n;

struct st {
	long long num;
	int c;
} str[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) {
		long long x;
		char y;
		scanf("%lld %c", &x, &y);
		str[i].num = x;
		str[i].c = y - 'c' + 1;
	}
	long long sum = 0;
	for (int is = 1, ie = n; is < ie;) {
		if (str[is].num > str[ie].num) {
			long long x = str[is].num;
			for (; ie > is && x > 0;) {
				if (str[ie].c != str[is].c) {
					if (x >= str[ie].num) {
						x -= str[ie].num;
						sum += str[ie].num;
						ie--;
					} else {
						str[ie].num -= x;
						sum += x;
						x = 0;
						break;
					}
				} else {
					if (x >= str[ie].num) {
						x -= str[ie].num;
						ie--;
					} else {
						str[ie].num -= x;
						x = 0;
						break;
					}
				}
			}
			is++;
		} else {
			long long x = str[ie].num;
			for (; is < ie && x > 0;) {
				if (str[is].c != str[ie].c) {
					if (x - str[is].num >= 0) {
						x -= str[is].num;
						sum += str[is].num;
						is++;
					} else {
						str[is].num -= x;
						sum += x;
						x = 0;
						break;
					}
				} else {
					if (x - str[is].num >= 0) {
						x -= str[is].num;
						is++;
					} else {
						str[is].num -= x;
						x = 0;
						break;
					}
				}
			}
			ie--;
		}
	}
	printf("%lld\n", sum);
	return 0;
}
