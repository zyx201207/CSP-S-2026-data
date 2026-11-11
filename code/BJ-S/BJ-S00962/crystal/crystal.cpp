#include <iostream>
using namespace std;
long long n, m, mins=1e12+10, maxs, ans;
long long a[500010];

int main () {
        freopen("crystal.in","r",stdin)
        freopen("crystal.out","w",stdout)
	cin >> n >> m;
	for (int i=1;i<=n;i++) {
		cin >> a[i];
	}
	sort (a+1, a+n+1);
    int k=a[2]-a[1];
    for (int cnt=0;cnt<=m;cnt+=k) {
        ans++;
    }
    cout << ans-1;
    return 0;
}

