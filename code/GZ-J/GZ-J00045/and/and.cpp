//GZ-J00045 ¸¶³¿³©
#include <bits/stdc++.h>
using namespace std;
long long sum;long long n,m;
long long f[200010];
long long b[200010];
void dfs(long long o,long long ssum) {
    if (o >= m) {sum = max(sum,ssum);return ;}
    for (long long j = 1;j<=n;++j) {
	    if (!b[j]) {
		    b[j] = 1;
	        if(o == 0) dfs(o+1,f[j]);
		    else dfs(o+1,ssum&f[j]);
			b[j] = 0;
		}
	}return ;
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	if (m == 0) {cout<<0;return 0;}
	cin>>f[1];sum= f[1];
	for (long long i = 2;i<=n;++i) {
	    cin>>f[i];
		sum&=f[i];
	}
	if (m == n) {cout<<sum;return 0;}
	long long ssum = 0;
	dfs(0,ssum);
	cout<<sum;
    return 0;
}
