#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
long long n,nn,m,a[200005],tl,s=1,sum,r,ss,d[200005];
long long g(long long x) {
	long long p=2,q=1;
	while(x>1) {
		if(x%2==1) {
			q*=p;
		}
		p=p*p;
		x/=2;
	}
	if(x==0) {
		return 1;
	} else {
		return p*q;
	}

}
bool cmp(long long x,long long y) {
	return x>y;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	nn=n;
	for(int i=1; i<=n; i++) {
		scanf("%lld",&a[i]);
		d[i]=a[i];
	}
	for(int i=1; i<=30; i++) {
		s*=2;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=30; i>=1; i--) {
		tl=0;
		r=g(i-1);
		for(int j=1; j<=n; j++) {
			if(a[j]/r%2==1) {
				tl++;
			}
		}
		if(tl==m) {
			if(ss==0) {
				for(int j=1; j<=n; j++) {
					a[j]%=s;
				}
				sort(a+1,a+n+1,cmp);
				sum=a[1];
				for(int j=2; j<=m; j++) {
					sum&=a[j];
				}
				printf("%lld",sum);
				return 0;
			} else {
				for(int j=1; j<=nn; j++) {
					d[j]%=ss;
				}
				sort(d+1,d+nn+1,cmp);
				sum=d[1];
				for(int j=2; j<=m; j++) {
					sum&=d[j];
				}
				printf("%lld",sum);
				return 0;
			}
		} else if(tl>m) {
			for(int j=1; j<=n; j++) {
				a[j]%=s;
			}
			sort(a+1,a+n+1,cmp);
			n=tl;
			if(ss==0) {
				ss=s;
			}
		}
		s/=2;
	}
	for(int j=1; j<=nn; j++) {
		d[j]%=ss;
	}
	sort(d+1,d+nn+1,cmp);
	sum=d[1];
	for(int j=2; j<=m; j++) {
		sum&=d[j];
	}
	printf("%lld",sum);
	return 0;
}
