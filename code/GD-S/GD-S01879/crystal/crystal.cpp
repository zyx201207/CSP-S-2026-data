#include<bits/stdc++.h>
using namespace std;
long long a[500007], s[500007];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m, ma = -1;
	cin >> n >> m;
	s[0] = 0;
	for(long long i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(long long i = 1; i <= n; i++){
		s[i] = s[i - 1] + a[i];
	}
	for(long long l = 1, r = 1; l <= n && r <= n; l++){
		while(a[r] * (r - l + 1) - (s[r] - s[l - 1]) <= m || r < l){
			r++;
			if(r > n + 1){
				break;
			}
		}
		r--;
		ma = max(ma, min(r, n) - l + 1);
	}
	cout << ma;
	return 0;
}
