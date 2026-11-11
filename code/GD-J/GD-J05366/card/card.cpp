#include <bits/stdc++.h>
using namespace std;
int a[500005], ans[500005], cnt[500005];
bool b[500005];
int main (){
	preopen("card.in", "r", stdin);
	preopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i]; 
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cnt[j] = 0;
		}
		for (int j = i; j <= n; j++){
			b[j] = true;
		}
		for (int j = 1; j <= i-1; j++){
			b[j] = false;
		}
		for (int j = i; j <= n; j++){
			cnt[a[j]]++;
			ans[a[j]]++;
			if (cnt[a[j]] > 1){
				int r = j;
				while (true){
					r--;
					if (a[j] == a[r] && b[r]){
						cnt[a[r]]--;
						ans[a[r]]--;
						b[r] = false;
						break;
					}
					if (b[r]){
						cnt[a[r]]--;
						ans[a[r]]--;
						b[r] = false;
					}
				}
			}
		}
	}
	for (int i = 1; i <= m; i++){
		cout << ans[i] << ' ';
	}
}
