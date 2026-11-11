#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n, a[10005], b[10005][10005], ans=1;
	int m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = n; i > 1; i--) {
		for(int j = i-1; j > 0; j--) {
			b[i][j] = a[i]-a[j];
		}
	}
	for(int i = n; i > 0; i--) {
		int cnt = i-1, cnt2, cnt3 = 0;
		cnt2 = b[i][cnt];
		while(cnt2 <= m && cnt != 1) {
			cnt--;
			cnt2 = cnt2 + b[i][cnt];
			cnt3++;
		}
		ans = max(ans, cnt3);
	}
	cout << ans << endl;
	return 0;
}

