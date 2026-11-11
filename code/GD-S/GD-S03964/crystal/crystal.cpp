#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],c,s,t,b[500001];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	if(a[2]-a[1]==a[3]-a[2]&&a[3]-a[2]==a[4]-a[3]) {
		for(int i=n;i>=2;i--) {
			b[i]=(a[2]-a[1])*(n-i+1);
			b[i]=b[i]*(n-i+2)/2;
		}
		for(int i=2;i<=n;i++)
		b[i-1]=b[i];
		b[n]=0;
		for(int i=1;i<=n;i++)
			if(m>=b[i]) {
				printf("%lld",n-i+1);
				break;
			}
		return 0;
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++)
			b[j]=a[j];
		t=m;
		c=1;
		if(a[i]==a[i-1]&&i!=1)
			continue;
		for(int j=i-1;j;j--) {
			if(b[i]-b[j]<=t) {
				t=t-(b[i]-b[j]);
				b[j]=b[i];
			}
			else
				break;
		}
		for(int j=2;j<=n;j++)
			if(b[j-1]==b[j])
				c++;
		s=max(s,c);
	}
	printf("%lld",s);
	return 0;
}
