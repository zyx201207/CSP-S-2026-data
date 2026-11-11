#include <bits/stdc++.h>
using namespace std;
long long sl[1000000];
char zf[1000005];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,h=1,r,pay=0;
	cin>>n;
	r=n;
	for (long long i=1; i<=n; i++) {
		cin>>sl[i]>>zf[i];
	}
	while (h<r) {
		long long a=min(sl[h],sl[r]);
		if (zf[h]!=zf[r]) {
			pay+=a;
			sl[h]-=a;
			sl[r]-=a;
		} else {
			sl[h]-=a;
			sl[r]-=a;
		}
		if (sl[h]==0) {
			h++;
		}
		if (sl[r]==0) {
			r--;
		}
	}
	cout<<pay;
	return 0;
}
