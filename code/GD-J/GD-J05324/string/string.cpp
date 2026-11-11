#include<bits/stdc++.h>
using namespace std;
int xa[10010110];
char xb[10000030];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	char k;
	long long n,h=0,title=0;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>h>>k;
		xa[i]=h;
		xb[i]=k;
		title+=h;
	}
	long long hf=title>>1;
	char ll,rr;

	long long l=0,r=0,lp=0,rp=n+1,jis=0,lo=0,ro=0;
	while(1) {
		if(l>=hf&&r>=hf) {
			break;
		}
		if(l<r) {
			if(l+=xa[lp+1]<hf) {
				lp++;
				l+=xa[lp];
				lo=xa[lp];
				ll=xb[lp];

			} else {
				lo=hf-l;
				l=hf;
				ll=xb[lp+1];
			}
		} else if(l>r) {
			if(r+=xa[rp-1]<hf) {
				rp--;
				r+=xa[rp];
				rr=xb[rp];
				ro=xa[rp];

			} else {
				ro=r-hf;
				rr=xb[rp-1];
				r=hf;
			}
		} else if(l==r) {
			if(l+=xa[lp+1]<hf) {
				lp++;
				l+=xa[lp];
				lo=xa[lp];
				ll=xb[lp];

			} else {
				lo=hf-l;
				l=hf;
				ll=xb[lp+1];
			}
			if(r+=xa[rp-1]<hf) {
				rp--;
				r+=xa[rp];
				rr=xb[rp];
				ro=xa[rp];

			} else {
				ro=hf-r;
				rr=xb[rp-1];
				r=hf;
			}
		}
		if(ll!=rr) {
			
			jis+=min(lo,ro);
			
		}
	}
	cout<<jis;
	return 0;
}
