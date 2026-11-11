#include<iostream>
#include<algorithm>
#include<cstring>

#define int long long

using namespace std;

const int M = 1000009;

int ji[M];

int a, b, c;
int ans = 0;

int zh[M];

int pd = 1;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &a, &b);
	for (int i = 1; i <= a; ++i) {
		scanf("%lld", &ji[i]);
		zh[i] = zh[i - 1] + ji[i];
		if (ji[i] != ji[i - 1] + 1) {
			pd = 0;
		}
	}
	if (pd == 1) {
		for (int i = 1; i <= a; ++i) {
			if (b < zh[i]) {
				printf("%lld", i);
				return 0;
			}
		}
	}
	sort(ji + 1, ji + a + 1);
	for (int i = 1; i <= a; ++i) {
		int bz = ji[i];
		int ky = b;
		int res = 0;
		for (int j = i; j >= 1; --j) {
			if (ky - (bz - ji[j]) >= 0) {
				ky -= (bz - ji[j]);
				++res;
			} else {
				break;
			}
		}
		ans = max(ans, res);
	}
	printf("%lld", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//贵州省 安顺市第二高级中学 郑焕博 GZ-S00151
