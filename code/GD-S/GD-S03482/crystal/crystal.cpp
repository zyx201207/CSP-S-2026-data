#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
typedef long long ll;
ll n,m,a[maxn],cf[maxn],l=1,r=2,ans=-1e18-10;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//n=read(),m=read();
	scanf("%lld%lld",&n,&m);
	//for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=2;i<n;i++) cf[i]=a[i]-a[i-1];
	if(n==0) printf("0");
	while(l<=n) {
		r=l+1;
		ll sum=0,de=1,num=1;
		while(r+1<=n&&sum+cf[r]*de<=m) {
			num++;
			sum=sum+cf[r]*de;
			r++,de++;
		}
		l++;
		ans=max(ans,num);	
	}
	printf("%lld",ans);
	return 0;
}
