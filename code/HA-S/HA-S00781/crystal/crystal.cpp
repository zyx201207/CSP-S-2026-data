#include<bits/stdc++.h>
using namespace std;

typedef long long lld;

const lld N=5e5+10;
const lld M=1e18;
lld n,m,a[N],ans,sum,BBB,n_2;
bool A,AAA,B;

int main () {
	freopen ("crystal.in","r",stdin);
	freopen ("crystal.out","w",stdout);

	scanf ("%lld%lld",&n,&m);
	n_2=n/2;
	sum=m;
	A=1,B=1;
	if (n%2LL!=0) {
		AAA=1;
	}
	for (lld i=1; i<=n; i++) {
		scanf ("%lld",&a[i]);
		if (A&&a[i]!=i) {
			A=0;
		}
		if (B&&(i>=3LL)) {
			if (a[i]-a[i-1LL]!=a[i-1LL]-a[i-2LL]) {
				B=0;
			}
		}
	}
	BBB=abs(a[n]-a[n-1]);
	if (B) {
		ans++;
		for (lld i=1; i<n_2&&sum; i++) {
			if ((i*2*BBB)<=0) {
				break;
			}
			if (sum-(i*2*BBB)>=0) {
				ans+=2;
				sum-=2*i*BBB;
			} else if (sum-(i*BBB)>=0) {
				ans++;
				sum-=i*BBB;
				break;
			}
		}
		if (sum-(n_2*2*BBB)>=0&&AAA) {
			ans+=2;
			sum-=n_2*2*BBB;
		} else if (sum-(n_2*BBB)>=0) {
			ans++;
			sum-=n_2*BBB;
		}
	} else {
		sort (a+1,a+1+n);
		lld ans1;
		for (lld i=n; i>0; i--) {
			ans1=0;
			sum=m;
			for (lld j=i; j>0; j--) {
				lld temp=abs(a[i]-a[j]);
				if (sum-temp>=0) {
					sum-=temp;
					ans1++;
				} else {
					break;
				}
			}
			ans=max(ans1,ans);
		}
	}
	printf ("%lld",ans);
	return 0;
}