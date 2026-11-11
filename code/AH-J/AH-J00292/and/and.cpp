#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=2e3+10;
LL n,m,a[N];
LL d[N][N];
int main(){//50
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(LL i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(LL i=0;i<=n;i++) d[i][0]=-1;
	for(LL j=0;j<=m;j++) d[0][j]=-1;
	for(LL i=1;i<=n;i++){
		for(LL j=1;j<=m;j++){
			if(i<j) d[i][j]=-1;
			else d[i][j]=max(LL(d[i-1][j-1]&a[i]),d[i-1][j]);
			cout<<d[i][j]<<"\t";
		}
		cout<<"\n";
	}
	printf("%lld",d[n][m]);
	return 0;
}
