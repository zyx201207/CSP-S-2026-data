#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=1,cnt;
long long a[214514],b[214514],c[214514];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++) {
		c[i]=0;
		scanf("%lld",&a[i]);
	}
	while(ans<=n) {
		cnt=0;
		for(long long i=ans;i<=n;i++) {
			for(long long j=1;j<=cnt;j++) {
				if(b[j]==a[i]) {
					cnt=j-1;
				}
			}
			cnt++;
			b[cnt]=a[i];
		}
		for(long long i=1;i<=cnt;i++) {
			c[b[i]]++;
		}
		ans++;
	}
	printf("%lld",c[1]);
	for(long long i=2;i<=m;i++) {
		printf(" %lld",c[i]);
	}
	return 0;
}
