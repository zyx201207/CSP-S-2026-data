#include<bits/stdc++.h>
#define int long long
using namespace std;
bool cmp(int x, int y) {
	return x>y;
}
int a[200005];
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> a[i];
	sort(a+1, a+n+1, cmp);
	if (m==1) {
		cout << a[1] << endl;
		return 0;
	} 
	int flag=(int)1<<30, ans=0;
	for (;flag>=1;flag>>=1) {
		bool pd=1;
		for (int i=1;i<=n;i++) {
			if (!(a[i]&flag)||flag>a[i]) {
				pd=0;
				if (i-1<m) {
					for (int j=1;j<i;j++) a[j]-=flag;
					if (i>1) sort(a+1, a+n+1, cmp);
					break;
				} else ans+=flag, n=i-1;
			}
		}
		if (pd) ans+=flag;
	}
	cout << ans << endl;
	return 0;
}
