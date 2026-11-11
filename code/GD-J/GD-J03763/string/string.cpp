#include <bits/stdc++.h>
using namespace std;
int n;
long long ans;
int a[20005];
char c[20005];

int main(){
	ios :: sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		cin >> c[i];
	}
	
	int l = 1;
	int r = n;
	ans = 0;
	while (l < r){
		if (c[l] != c[r]){
			if (a[l] - a[r] > 0){
				ans += a[r];
				cout << ans << endl;
			}
			else{
				ans += a[l];
				cout << ans << endl;
			}
		}
		if (a[l] - a[r] > 0){
			a[l] -= a[r];
			r -= 1;
		}
		else if (a[l] - a[r] < 0){
			a[r] -= a[l];
			l += 1;
		}
		else{
			l+=1;
			r-=1;
		}
	}
	
	cout << ans;
	
	return 0;
}
 
