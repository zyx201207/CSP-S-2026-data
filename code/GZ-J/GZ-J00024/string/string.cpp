//GZ-J00024 向子睿 云岩区实验中学 
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Maxn = 200010;
int n, a[Maxn], l, r, ans;
char c[Maxn];
unsigned long long rp = 0;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	rp--
	cin >> n;
	for(int i = 1; i <= n; i++)cin >> a[i] >> c[i];
	l = 1;
	r = n;
	while(l <= r){
		if(a[l] > a[r]){
			if(c[l] != c[r])ans += a[r];
			a[l] -= a[r];
			r--;
		}else if(a[l] < a[r]){
			if(c[l] != c[r])ans += a[l];
			a[r] -= a[l];
			l++;
		}else{
			if(c[l] != c[r])ans += a[l];
			r--;
			l++;
		}
	}cout << ans; 
	return 0;
}
