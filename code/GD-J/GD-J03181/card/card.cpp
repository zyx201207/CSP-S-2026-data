#include <bits/stdc++.h>
using namespace std;
const int M=1e6;
long long int ans[M];
long long int f[M];
long long int a[M];
long long int b[M];
long long int n,m,x=1;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(long long int i=1;i<=n;i++) scanf("%lld",&a[i]);
	while(n--) {
		long long int sum=0;
		for(long long int i=x;i<=n;i++) {
			if(f[a[i]]==0) {
				b[++sum]=a[i];
				f[a[i]]++;
			}
			else {
				sum=1;
				b[1]=a[i];
				for(long long int j=1;j<=n;j++) f[i]=0;
			}
		}
		for(long long int i=1;i<=sum;i++) {
			ans[b[i]]++;
		}
		for(long long int i=1;i<=n;i++) {
			f[i]=0;
		} 
		x++;
	}
	for(long long int i=1;i<=m;i++) {
		printf("%lld ",ans[i]);
	}
	return 0;
}
