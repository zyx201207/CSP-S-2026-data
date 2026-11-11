#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5+7;
long long a[N];
long long ans = 0;
string s;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n; cin >> n;
	long long nn = 0;
	for(long long i = 1; i <= n ; i++){
		scanf("%lld", &a[i]);
		cin >> s[i];
		nn += a[i]; 
	}
	long long l = 1, r = n,ll = 1 , rr = nn;
	while(ll <= rr){
		long long maxx = max(a[l], a[r]);
		if(a[l] > a[r]){
			long long k = a[l], kk = r;
			bool tt = 1;
			while(1){
				if(k == 0)break;
				if(a[kk] > k){
					if(s[kk] != s[l]) ans += k; 
					tt = false;
					a[kk] -= k;
					break;
				}
				if(s[kk] != s[l]){
					ans += a[kk];
				}
				a[l] -= a[kk];
				k--;
			}
			l++;
			if(tt){
				r--;
			}
		}else if(a[l] < a[r]){
			long long k = a[r], kk = r;
			bool tt = 1;
			while(1){
				if(k == 0)break;
				if(a[kk] > k){
					if(s[kk] != s[l]) ans += k; 
					tt = false;
					a[kk] -= k;
					break;
				}
				if(s[kk] != s[r]) ans += a[kk];
				a[r] -= a[kk];
				k--;
			}
			r--;
			if(tt){
				l++;
			}
		}else{
			if(s[r] != s[l]) ans += a[r]; 
			r--,l++;
		}
		ll += maxx;
		rr -= maxx;
	}
	cout << ans;
	return 0;
}
