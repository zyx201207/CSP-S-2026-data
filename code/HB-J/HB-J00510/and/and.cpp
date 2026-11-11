#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],maxn=0;
int main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	if (n<=2000){
		if (m==1) for (int i=1;i<=n;i++) maxn=max(maxn,a[i]);
		if (m==2) for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) if (i!=j) maxn=max(maxn,a[i]&a[j]);
		if (m==n){
			maxn=a[1];
			for (int i=2;i<=n;i++) maxn=maxn&a[i];
		}
		printf("%lld",maxn);
	}else {
		sort(a+1,a+1+n);
		cout<<a[n-m+1];
	}
	return 0;
}
