//GZ-S00033 ¸¶³¿³© 
#include <bits/stdc++.h>
using namespace std;
long long f[500010],dp[500010],o;
long long d;long long n;long long sum = 0;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long c,t;cin>>c>>t;
    for (;t--;) {
	    cin>>n>>d;
	    for (long long i = 1;i<=n;++i) {
		    cin>>f[i];if (f[i]%2 && f[i]-f[1]>=d == 0) ++sum;
		}
		cout<<sum<<'\n';
	}
    return 0;
}
