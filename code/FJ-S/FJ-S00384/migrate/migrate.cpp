#include <bits/stdc++.h>
using namespace std;
inline long long read() {
	long long x=0,f=1;
	char c=getchar();
	while(c<'0'||'9'<c) {
		if(c=='-') f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
inline void write(long long x) {
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
int c,t,n;
long long d,a[2000010],sum=0;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();
	t=read();
	while(t--) {
		n=read();
		d=read();
		for(int i=1; i<=n; i++) a[i]=read();
		sum=0;
		for(int i=1; i<n; i++) {
			long long x=a[i]+d;
			int l=i,r=n;
			while(l<=r) {
				int mid=(l+r)/2;
				if(a[mid]<=x) l=mid+1;
				else r=mid-1;
			}
			if(l<=n&&a[l]-a[r-1]<=d&&a[l]-a[r-2]>d) sum++;
		}
		write(sum);
		putchar('\n');
	}
	return 0;
}
