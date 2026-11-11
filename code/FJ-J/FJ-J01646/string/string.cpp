#include<bits/stdc++.h>
#define int long long
using namespace std;
int n , a[200010] , sum , ans;
char ch[200010];
string s;
signed main(){
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i] >> ch[i];
		sum += a[i];
	}
	if (sum <= 100000){
		int ans = 0;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= a[i]; j++){
				s += ch[i];
			}
		}
		for (int i = 0 , j = sum - 1; i < j; i++ , j--){
			if (s[i] != s[j]) ans++;
		}
		cout << ans;
		return 0;
	}
	int mid = sum / 2 , l = 0 , r = 0 , nl = 0 , nr = 0  , lp = 0 , rp = n + 1;
	while (1){
		if(l == mid){
			break;
		}
		nl = l , lp++; 
		l += a[lp]; 
		if (l > mid){
			l = mid;
		}
		while (l > r){
			rp--;
			nr = r;
			r += a[rp];
			if (l <= r){
				a[rp] = r - l;
				rp++;
				r = l;
			}
			if (ch[lp] != ch[rp - (l == r)]){
				ans += r - nr;
			}
		}
		//cout << l << " " << r << " " << ans << "\n";
	} 
	cout << ans;
	return 0;
}
