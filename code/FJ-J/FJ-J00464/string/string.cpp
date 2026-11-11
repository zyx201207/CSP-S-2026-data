#include<bits/stdc++.h>
using namespace std;
long long n,ans=0;
int a[200005];
char c[200005];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(long long i=1; i<=n; i++) {
		cin >> a[i] >> c[i];
	}
	long long i=1;
	while(i<n) {
		while(a[i]>0) {
			if(c[i]!=c[n]) {
				if(a[i]>=a[n]) {
					ans+=a[n];
				} else if(a[i]<a[n]) {
					ans+=a[i];
				}
			}
			if(a[i]<a[n]) {
				a[n]-=a[i];
				break;
			}
			a[i]-=a[n];
			n--;
		}
		i++;
	}
	cout << ans;
	return 0;
}
