#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10;
int n, a[N], ans;
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	int suml = 1, sumr = 0;
	int m = 0;
	for(int i=1;i<=n;i++) cin >> a[i] >> c[i], sumr += a[i];
	suml = 1; m = sumr;
	int l = 1, r = n;
	while(l < r){
		int l1 = suml, r1 = suml + a[l] - 1;
		int l2 = sumr - a[r] + 1, r2 = sumr;
		int ll = m - r2 + 1, rr = m - l2 + 1;
		int len = min(r1,rr)-max(l1,ll)+1;
		if(len>0){
			if(c[l] != c[r]) ans += len;
			if(ll <= l1 && r1 <= rr) suml += a[l], l++;
			else if(l1 <= ll && rr <= r1) sumr -= a[r], r--;
			else if(ll <= r1 && ll >= l1) suml += a[l], l++;
			else sumr -= a[r], r--;
		}else{
			if(ll >= r1) suml += a[l], l++;
			else sumr -= a[r], r--;
		}
	}
	cout << ans << '\n';
	return 0;
}
