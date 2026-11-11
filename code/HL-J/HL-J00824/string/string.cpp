#include <bits/stdc++.h>
using namespace std;
long long n,a[200005];
long long b1,b2,ans;
char b[200005];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++) {
		cin >> a[i] >> b[i];
	}
	b1=1;
	b2=n;
	while(b2>b1) {
		if(b[b1]!=b[b2]) {
			ans+=min(a[b1],a[b2]);
		}
		if(a[b1]<a[b2]) {
			a[b2]-=a[b1];
			b1++;
		}
		else if(a[b1]>a[b2]) {
			a[b1]-=a[b2];
			b2--;
		}
		else {
			b1++;
			b2--;
		}
	}
	cout << ans;
	return 0;
}
//I remember every time I smell the rain.
