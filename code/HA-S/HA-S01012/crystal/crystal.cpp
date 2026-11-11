#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5+5;
long long m, n, maxCnt;
long long crystals[MAXN], presum_crystals[MAXN];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(long long i = 0; i < n; i++) cin >> crystals[i];
	sort(crystals, crystals + n);
	presum_crystals[0] = crystals[0];
	for(long long i = 1; i < n; i++) presum_crystals[i] = presum_crystals[i - 1] + crystals[i];
	long long j = 0;
	for(long long i = 0; i < n; i++) {
		for(; j < n; j++) {
			if(crystals[j] * (j - i + 1) - (presum_crystals[j] - presum_crystals[i] + crystals[i]) <= m) {
				maxCnt = max(j - i + 1, maxCnt);
				continue;
			} else break;
		}
	}
	cout << maxCnt << '\n';
	return 0;
}