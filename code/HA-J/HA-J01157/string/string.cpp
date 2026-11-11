#include<bits/stdc++.h>
using namespace std;
long long a[200010];
char b[200010];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0;
	cin>>n;
	for(long long i=1; i<=n; i++) {
		cin>>a[i]>>b[i];
	}
	long long l=1,r=n;
	while(l<=r) {
		if(a[l]>a[r]) {
			if(b[l]!=b[r]) {
				ans+=a[r];
			}
			a[l]-=a[r];
			a[r]=0;
			r--;
		} else if(a[l]<a[r]) {
			if(b[l]!=b[r]) {
				ans+=a[l];
			}
			a[r]-=a[l];
			a[l]=0;
			l++;
		} else {
			if(b[l]!=b[r]) {
				ans+=a[l];
			}
			a[l]=0,a[r]=0;
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}
