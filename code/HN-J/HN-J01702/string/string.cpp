#include<bits/stdc++.h>
using namespace std;
int n;
string s;
long long s1;
long long b;
struct node {
	char c;
	long long l1,r1;
} jiru[2*100000+10];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		long long  x;
		char a;
		cin>>x;
		cin>>a;
		jiru[i].c=a;
		jiru[i].l1=s1+1;
		jiru[i].r1=s1+x+1;
		s1+=x;
	}
	long long  l=1,r=jiru[n].r1;
	long long  ll=1,rr=n;
	while(1) {
		if(l<r) {
			cout<<b;
			break;
		}
		if(jiru[ll].c==jiru[rr].c) {
			if(jiru[ll].r1-l<r-jiru[rr].l1) {
				r=r-(jiru[ll].r1-l);
				ll++;
				l=jiru[ll].l1;
			} else if(jiru[ll].r1-l>r-jiru[rr].l1) {
				l=l+(r-jiru[rr].l1);
				rr--;
				r=jiru[rr].r1;
			} else {
				rr--;
				ll++;
				r=jiru[rr].r1;
				l=jiru[ll].l1;
			}
		} else {
			if(jiru[ll].r1-l<r-jiru[rr].l1) {
				b+=jiru[ll].r1-l;
				ll++;
				r=r-(jiru[ll].r1-l);
				l=jiru[ll].l1;
			} else if(jiru[ll].r1-l>r-jiru[rr].l1) {
				b+=r-jiru[rr].l1;
				rr--;
				l=l+(r-jiru[rr].l1);
				r=jiru[rr].r1;
			} else {
				b+=r-jiru[rr].l1;
				ll++;
				rr--;
				l=jiru[ll].l1;
				r=jiru[rr].r1;
			}
		}
	}
	return 0;
}
