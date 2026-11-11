#include<bits/stdc++.h>
using namespace std;
const int N=200005,M=500005,L=300005;
long long n,m,a[M],num[L];
long long sf[L];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=0; i<n; i++) scanf("%lld",&a[i]);
	for(long long i=0; i<n; i++) {
		int sg=i;
		for(long long j=1; j<=m; j++) sf[j]=N;
		for(long long j=i; j<n; j++) {
			if(sf[a[j]]!=N) {
				long long ls=sf[a[j]];
				for(long long l=j-1; l>=ls; l--) {
					if(sf[a[l]]!=N) {
						sf[a[l]]=N;
						num[a[l]]--;
					}
				}
				sg=j;
			}
			sf[a[j]]=min(j,sf[a[j]]);
			num[a[j]]++;
		}
	}
	for(int i=1; i<=m; i++) printf("%lld ",num[i]);
	return 0;
}
