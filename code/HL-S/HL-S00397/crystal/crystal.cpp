#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (long long i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for (long long i = 2;i <= n;i++){
		long long p = m;
		long long x = 0;
		for (int j = i;j >= 1;j--){
			p -= a[i]-a[j];
			if (p < 0){
				ans = max(ans,x);
				break;
			}
			x++;
		}
		ans = max(ans,x);
	}
	cout << ans;
	return 0;
}