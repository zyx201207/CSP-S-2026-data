#include <bits/stdc++.h>
using namespace std;
constexpr int N=5e5+5;
int n,ans;
bool fun;
long long m,a[N],d[N],cnt;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for (int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
		d[i]=a[i]-a[i-1];
	}
	for (int i=2;i<=n;++i){
		if (d[i]!=d[i-1]){
			fun=1;
			break;
		}
	}
	int diff=d[1];
	if (!fun){
		long double ttt=sqrt(8*m+diff)/(2.0*diff)-0.5;
		printf("%lld",(long long)ceil(ttt)+1);
		return 0;
	}
	sort(a+1,a+1+n);
	for (int i=n;i>=1;--i){
		bool flag=0;
		cnt=0;
		for (int j=1;j<i;++j){
			cnt+=(a[i]-a[j]);
			if (cnt>m) {flag=1;break;}
		}
		if (cnt>m) flag=1;
		if (!flag) {ans=i;break;}
	}
	if (ans!=1) {printf("%d",ans);return 0;}
	int tt=1;
	for (int i=2;i<=n;++i){
		if (a[i]!=a[i-1]) tt=1;
		else ++tt;
		ans=max(ans,tt);
	}
	printf("%d",ans);
	return 0;
}
