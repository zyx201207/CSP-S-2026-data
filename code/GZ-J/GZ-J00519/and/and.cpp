//GZ-J00519,lijunshen 
#include <bits/stdc++.h>
using namespace std;
int m, n;
int a[200005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0;i < n;i++)cin >> a[i]; 
	if (m == 1){
		int mx = 0;
		for (int i = 0;i < n;i++)mx = max(mx, a[i]);
		cout << mx;
	}
	else if (m == n){
		int ad = (1 << 30)-1;
		for (int i = 0;i < n;i++){
			ad = ad&a[i];
		}
		cout << ad;
	}
	else if (m == 2){
		int mx = 0;
		for (int i = 0;i < n;i++){
			for (int j = i+1;j < n;j++){
				mx = max(mx, a[i]&a[j]);
			}
		}
		cout << mx;
	}
	return 0;
}
