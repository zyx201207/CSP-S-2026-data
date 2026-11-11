#include<bits/stdc++.h>
using namespace std;
#define int long long
int read() {
	int x=0,f=1;char chr=getchar();
	while (chr<'0'||'9'<chr){if(chr=='-')f=-f;chr=getchar();}
	while ('0'<=chr&&chr<='9'){x=x*10+chr-'0';chr=getchar();}
	return x*f;
} 
const int N = 5e5 + 10;
int n,m;
int a[N];
int ans;
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n = read(),m = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
	}
	sort(a + 1,a + n + 1);
	for (int i = 2,j = 1,k = a[2] - a[1]; i <= n; i++) {
		while (k > m) {
			k -= a[i] - a[j]; 
			j++;
		}
		ans = max(ans,i - j + 1);
		k += (i - j + 1) * (a[i + 1] - a[i]);
	}
	cout << ans << "\n";
	return 0;
}
