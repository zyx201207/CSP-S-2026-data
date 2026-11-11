//GZ-S00033 ¸¶³¿³© 
#include <bits/stdc++.h>
using namespace std;
long long f[500010];
long long dp[500010];
struct ff{
    long long a,b;
}w[500010];long long max = 0;
long long u[500010];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long c,n,m,d,q;
    for (logn long i = 1;i<=m;++i) {
	    cin>>f[i];
	}
	long long j = 1
	for (logn long i = 1;i<=n;++i) {
	    long long x;cin>>x; 
	    for (;j<=x;++j) {
		    cin>>w[j].a>>w[j].b;
		}
	}
	for (long long i = 1;i<=q;++i) {
	    long long x,y;cin>>x>>y;
	    cout<<f[x]+f[y]+w[f[x].b]<<'\n';
	}
    return 0;
}
