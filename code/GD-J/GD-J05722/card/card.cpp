#include<bits/stdc++.h>
#define I return
#define AK 0
#define IOI ;
using namespace std;
long long n, m, k, x, y, a[1234567], b[1234567], ans[1234567], cnt[1234567], f[1234567], fa[1234567], rcnt[1234567];
bool cmp(long long x, long long y) {
	return b[x] < b[y];
}
void findad(int x, int sum, int sta) {
	rcnt[x] += sum;
	if(fa[x] == x)return;
	else findad(fa[x], sum, sta), fa[x] = fa[fa[x]];
}
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i], b[n - i + 1] = a[i];
	for(int i = 1; i <= n; i++)a[i] = b[i], b[i] = 0;
	for(int i = 1; i <= n; i++) {
		if(i == 1)b[a[i]] = 1, fa[i] = 1;
		else if(!b[a[i]])b[a[i]] = i, fa[i] = i - 1;
		else fa[i] = b[a[i]];
		cnt[b[a[i]]]++;
	}
	for(int i = n; i >= 1; i--)findad(i, cnt[i], i);
	for(int i = 1; i <= m; i++)f[i] = i;
	sort(f + 1, f + m + 1, cmp);
	for(int i = 1; i <= m; i++)ans[f[i]] += rcnt[b[f[i]]];
	for(int i = 1; i <= m; i++)cout << ans[i] << " ";
	cout << '\n';
	return 0;
}
