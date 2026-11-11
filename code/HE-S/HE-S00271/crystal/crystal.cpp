#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+10;
int n,m,a[N],dif[N],tong[N];
bool eqdif=1;
void Equ30() {
	int d = a[2]-a[1];
	int x = 1;
	while(x <= n && x*(x+1)/2*d <= m) x++;
	cout << x;
}
void f() {
	for(int i = 1;i <= n;i++) tong[dif[i]]++;
	int ans = 1;
	for(int i = 0;i <= dif[n];i++) {
		int res = tong[i],k = m;
		for(int j = i-1;j >= 0;j--) {
			if(tong[j] == 0) continue;
			int dk = min(tong[j],k/(i-j));
			res += dk;
			k -= (i-j)*dk;
			if(k <= 0) break;
		}
		ans = max(ans,res);
	}
	cout << ans;
}
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		if(i > 2 && a[i] - a[i-1] != a[i-1]-a[i-2]) eqdif = 0;
	}
	if(eqdif) {
		Equ30();
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++)dif[i] = a[i]-a[1];
	if(dif[n] <= 6000) {
		f();
		return 0;
	}
	int ans = 1;
	for(int i= 1;i <= n;i++) {
		int srd = dif[i],cur = 1;
		int k = m;
		for(int j = i-1;j >= 1;j--) {
			if(k >= srd-dif[j]) {
				k -= srd-dif[j];
				cur++;
			}
		}
		ans = max(ans,cur);
	}
	cout << ans;
	return 0;
}
