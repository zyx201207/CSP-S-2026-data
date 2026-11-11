//GZ-S00033 ¸¶³¿³© 
#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long f[500010],dp[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (long long i = 1;i<=n;++i) {
	    cin>>f[i];
	}
	long long shi = 1;
	sort(f+1,f+1+n);
	long long sum = 0;long long top = 0;
	for (long long i = 2;i<=n;++i) {
	    sum+=abs(f[i]-f[i-1])*(i-1-top);
	    for (;sum>m && top+1<i;) sum-=abs(f[i]-f[++top]);
	    shi = max(shi,i-top);
	    //cout<<shi<<' '<<i<<'\n';
	}cout<<shi;
    return 0;
 }
