#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n , m;
	long long a[200005] , ans = 0;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for(int i = m;i <= n;i++){
		long long x = a[i - m + 1];
		for(int j = i - m + 2;j <= i;j++){
			x = x & a[j];
		}
		ans = max(ans , x);
	}
	cout << ans;
	return 0;
}
