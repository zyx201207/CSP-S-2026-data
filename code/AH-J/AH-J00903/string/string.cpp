#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, a[200005];
	long long ans = 0;
	char c[200005];
	bool ok = true;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i] >> c[i];
	for(int i = 1; i < n; i++)
		if(c[i] != c[i + 1]) ok = false;
	int l = 1, r = n;
	while(l < r && !ok){
		if(a[l] == a[r] && c[l] == c[r]){
			l++;
			r--;
		}
		else if(c[l] == c[r] && a[l] != a[r]){
			if(a[l] > a[r]){
				ans += a[l] - a[r];
				a[l] -= (a[l] - a[r]);
				r -= a[r];
			}
			else if(a[l] < a[r]){
				ans += a[r] - a[l];
				a[r] -= (a[r] - a[l]);
				l += a[l];
			}
		}
		else if(a[l] == a[r] && c[l] != c[r]){
			ans += a[l];
			l++;
			r--;
		}
		else{
			if(a[l] > a[r] && c[l] != c[r]){
				ans += a[r];
				a[l] -= (a[l] - a[r]);
				r--;
			}
			else if(a[l] < a[r] && c[l] != c[r]){
				ans += a[l];
				a[r] -= (a[r] - a[l]);
				l++;
			}
		}
	}
	cout << ans;
	return 0;
}
