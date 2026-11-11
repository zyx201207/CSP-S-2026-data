#include<bits/stdc++.h>
using namespace std;
#define int long long
//const int mod=;

int n,m;
int a[500005];
int b[500005];

int read() {
	int x=0,f=1,a=getchar();
	while (a<'0'||a>'9') {
		if (a=='-') f=-1;
		a=getchar();
	}
	while ('0'<=a&&a<='9') x=x*10+a-'0',a=getchar();
	return x*f;
}

signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

//	scanf("%lld%lld",&n,&m);
	n=read(),m=read();
	for (int i=1; i<=n; i++) a[i]=read();
//	 scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for (int i=1; i<=n; i++) b[i]=b[i-1]+a[i];
	int ans=0;
	for (int i=1; i<=n; i++) {
		int l=1,r=i;
		while (l<r) {
			int mid=l+r>>1;
			if (a[i]*(i-mid+1)-(b[i]-b[mid-1])<=m) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-r+1);
	}
	printf("%lld\n",ans);

	return 0;
}

