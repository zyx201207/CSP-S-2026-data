#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+5;
ll n,m,a[N],f[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for (ll i = 1;i<=n;i++){
    	scanf("%lld",&a[i]);
	}
	f[0] = 4294967295;
	for (ll i = 1;i<=n;i++){
		for (ll j = m;j>=1;j--){
			f[j] = max(f[j],f[j-1]&a[i]);
		}
	}
	printf("%lld\n",f[m]);//30
	return 0;
}

