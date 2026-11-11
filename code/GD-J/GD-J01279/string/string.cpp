#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[200005];
char c[200005];
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i] >> c[i];
	int ans = 0;
	for(int i = 1, j = n; i < j; ){
		if(c[i] != c[j]){
			if(a[i] > a[j])
				a[i] -= a[j], ans += a[j], j--;
			else if(a[i] == a[j])
				ans += a[i], i++, j--;
			else
				a[j] -= a[i], ans += a[i],i++;
		}
		else{
			if(a[i] > a[j])
				a[i] -= a[j], j++;
			else if(a[i] == a[j])
				ans += a[i], i++, j--;
			else
				a[j] -= a[i], j--;
		}
	}	
	cout << ans;
	
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b


*/
