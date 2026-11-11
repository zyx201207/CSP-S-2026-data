#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,m,a[500001],ans = 1,sum[500001];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for (int i = 1;i <= n;i++){
		sum[i] = sum[i - 1] + a[i];
	}
	bool isB = 1;
	for (int i = 3;i <= n;i++){
		if (a[i] - a[i - 1] != a[2] - a[1]){
			isB = 0;
			break;
		}
	} 
	if (isB){
		int d = a[2] - a[1];
		int i = n;
		for (int i = 1;i <= n;i++){
			//j在[id,i]范围内所有a[j]与a[i]之差的和 = 0 + d + 2d + 3d + ... + (i-id)*d = (i - id + 1) * (i - id) / 2 * d
			int l = 1,r = i,id;
			while (l <= r){
				int mid = (l + r) / 2;
				if ((i - mid + 1) * (i - mid) / 2 * d <= m){
					id = mid;
					r = mid - 1;
				}
				else {
					l = mid + 1;
				}
			}
			ans = max(ans,i - id + 1);
		}
		cout << ans;
		return 0;
	} 
	for (int i = 1;i <= n;i++){
		int l = 1,r = i,id;
		while (l <= r){
			int mid = (l + r) / 2;
			if ((i - mid + 1) * a[i] - (sum[i] - sum[mid - 1]) <= m){
				id = mid;
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}
		ans = max(ans,i - id + 1);
	}
	cout << ans;
	return 0;
} 
/*
5 5
2 4 6 8 10

*/
//这题有望AC 
