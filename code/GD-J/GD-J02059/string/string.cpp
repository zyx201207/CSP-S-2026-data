#include<bits/stdc++.h>
using namespace std;
long long n,r,l,r1,l1,t;
struct llu {
	long long a;
	char c;
} a[200010];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	l=1;
	r=n;
	for(int i=1; i<=n; i++) {
		cin>>a[i].a>>a[i].c;
	}
	while(l<r) {
		if(a[l].c!=a[r].c) {
			t+=min(a[r].a,a[l].a);
//			cout<<a[r].c;
		}
		if(a[r].a-r1!=a[l].a-l1) {
			if(a[r].a-r1>a[l].a-l1) {
				r1+=a[r].a-a[l].a;
				l++;
				l1=0;
			} else {
				l1+=a[l].a-a[r].a;
				r--;
				r1=0;
			}
		} else {
			l++;
			r--;
		}
	}
//	if(n%2!=0)
//	t--;
	cout<<t;
	return 0;
}

