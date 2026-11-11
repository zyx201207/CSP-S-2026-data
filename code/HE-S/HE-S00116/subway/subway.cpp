#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5090;
int c,n,m,d,q,w[N],k[N],t[N][N],a[N][N];
int32_t main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
	for (int i=0;i<=n;i++) {
		scanf("%lld",&w[i]);
	}
	for (int i=1;i<=n;i++) {
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++) {
			scanf("%lld %lld",&a[i][j],&t[i][j]);
		}
	}
	while (q--) {
		int x,y;
		scanf("%lld %lld",&x,&y);
		for(int i=x;i<=y;i++) {
			for(int j=1;j<=k[i];j++) {
				sum+=t[i][j];
			}
		}
		printf("%lld",sum);
	}
	return 0;
}

