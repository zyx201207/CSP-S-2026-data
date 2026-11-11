//GZ-J00045 ¸¶³¿³©
#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long f[500010];
int tt[500010];
set <long long> q;
long long top = 0;long long zz[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (long long i = 1;i<=n;++i) {
	    cin>>f[i];
	}
	for (long long i = 1;i<=n;++i) {
		for (long long j = i;j<=n;++j) {
		    if(q.count(f[j])) {
			    for(;zz[top] != f[j] && top>0;) --top;
				if (top>0) --top;
			}
			q.insert(f[j]);
			zz[++top] = f[j];
		}
	    for (long long k = 1;k<=top;++k) {
		    ++tt[zz[k]];
		}
		top = 0;q.clear();
	}
	for (long long i = 1;i<=m;++i) {cout<<tt[i]<<' ';}
    return 0;
}
