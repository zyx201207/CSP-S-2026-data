#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 500005;
int n, m, a[N], p[N], ans;
signed main (){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%lld%lld",&n,&m);
	for(int i = 1; i <= n; i ++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i = 1; i <= n; i ++){
		p[i] = p[i-1] + a[i];
	}
	int z = 1;
	for(int i = 1; i <= n; i ++){
		while((i-z+1) * a[i] - (p[i] - p[z-1]) > m) z++;
		ans = max(ans, i - z + 1);
	}
	cout << ans << endl;
}
