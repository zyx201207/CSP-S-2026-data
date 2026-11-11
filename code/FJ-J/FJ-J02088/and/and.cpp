#include <bits/stdc++.h>
using namespace std;

int n, m, a[200010];
int s[50][200010];
bool isture_s[50];
int allture[50];
int two[50];
int ans = 1 << 31 - 1;
int thein[200010], top = 0;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	two[0] = 1;
	for (int i = 1;i <= 30;i++) {
		two[i] = two[i - 1] * 2;
	}
	scanf("%d%d", &n, &m);
	for (int i = 1;i <= n;i++) {
		scanf("%d", &a[i]);
	}
	
	for (int i = 1;i <= n;i++) {
		for (int j = i + 1;j <= n;j++) {
			ans = max(ans, a[i] & a[j]);
		}
	}
	
	printf("%d", ans);
	fclose(stdin);
	fclose(stdout);
}
