#include <bits/stdc++.h>
using namespace std;

int a[500005];
int cnt[27778];

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	int ans1 = 0, ans2 = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		cnt[a[i]] ++;
	}
	if (m == 1){
		cout << n;
		return 0;
	}
	for (int j = 1; j <= n; j++){
		for (int i = n-1; i >= j; i--){
			if (a[n] == a[i]){
				if (a[n] == 1){
					ans1 ++;
					ans2 += (n-1 - i + 1);
					break;
				}
				else{
					ans1 += (n-1 - i + 1);
					ans2 ++;
					break;
				}
			}
		}
		if (j == n){
			if (a[n] == 1){
				ans1 ++;
			}
			else{
				ans2 ++;
			}
		}
	}
	cout << ans1-1 << " " << ans2-1;
	return 0;
}

