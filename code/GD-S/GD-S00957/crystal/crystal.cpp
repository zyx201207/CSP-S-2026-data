#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50;
int n , m;
long long a[N];
int f[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	int l = 1 , r = n;
	int k = (l + r + 1) / 2;
	auto x = lower_bound(a + 1 , a + 1 + n , a[k]) - a;
	auto y = upper_bound(a + 1 , a + 1 + n , a[k]) - a;
	int ans = y - x;
	int p = k - 1;
	while(p > 0){
		int s = a[k] - a[p];
		if(m >= s){
			ans++;
			m -= s;
		}
		p--;
	}
	cout << ans ;
	return 0;
}
