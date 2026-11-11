#include<bits/stdc++.h>
#include<string>
using namespace std;
struct a {
	long long x;
	char w;
} a[200005],b[200005];
long long n;

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i = 1,j = n; i<=n; i++,j--) {
		int x;
		char y;
		cin>>x>>y;
		a[i] = {x,y};
		b[j] = {x,y};
	}
	long long ac = 0,bc = 0,tot = 0;
	char aa,bb;
	for(int i = 1,j = 1;;) {
		bool cqa = 0,cqb = 0;
		if(ac == 0 && i<=n) {
			ac += (long long)a[i].x;
			i++;
			cqa = 1;
		}
		if(bc == 0 && j<=n) {
			bc += (long long)b[j].x;
			j++;
			cqb = 1;
		}
		if(cqa) aa = a[i-1].w;
		if(cqb) bb = b[j-1].w;
		if(aa != bb) {
			if(ac > bc) {
				ac -= bc;
				tot += bc;
				bc = 0;
			} else if(ac < bc) {
				bc -= ac;
				tot += ac;
				ac = 0;
			} else {
				tot += ac;
				ac = bc = 0;
			}

		} else {
			if(ac > bc) {
				ac -= bc;
				bc = 0;
			} else if(ac < bc) {
				bc -= ac;
				ac = 0;
			} else {
				ac = bc = 0;
			}
		}
		if(i > n && j > n) break;
//		printf("%lld\n",tot);
	}
	printf("%lld\n",tot/2);
	return 0;
}
