#include <bits/stdc++.h>
using namespace std;
long long a[1000010];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	long long m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	long long cnt = 0, pos = 0;
	long long mid = (a[1] + a[n]) / 2;
	while (m > 0){
		if (cnt % 2 == 0) pos++;
		m -= pos;
		cnt++;
	}
	if (m < 0) cnt--;
	cout << cnt+1;
	return 0;
}
