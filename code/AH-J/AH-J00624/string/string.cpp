#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,a[200005],b[200005],s,t,i,j,k,ans;
char str[5],c[200005],d[200005];
int main(void) {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(i=0;i<n;++i) scanf("%lld%s",&a[i],str),s+=a[i],c[i]=str[0];
	for(i=0;i<n;++i) {
		if(t+a[i]<s/2) t+=a[i],b[i]=a[i],d[i]=c[i];
		else {
			if(a[i]==s/2-t) {
				b[i]=a[i],d[i]=c[i];
				++i;
				break;
			} else {
				b[i]=s/2-t,d[i]=c[i];
				a[i]-=b[i];
				break;
			}
		}
	}
	if(s&1) {
		if(a[i]>1) --a[i];
		else ++i;
	}
	for(j=0,k=i,i=n-1;b[j]||i>=k;) {
		if(c[i]==d[j]) {
			if(a[i]==b[j]) --i,++j;
			else if(a[i]>b[j]) a[i]-=b[j],++j;
			else b[j]-=a[i],--i;
		} else {
			if(a[i]==b[j]) ans+=a[i],--i,++j;
			else if(a[i]>b[j]) ans+=b[j],a[i]-=b[j],++j;
			else ans+=a[i],b[j]-=a[i],--i;
		}
	}
	printf("%lld",ans);
	return 0;
}
