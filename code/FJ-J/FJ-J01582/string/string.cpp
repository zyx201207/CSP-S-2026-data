#include<bits/stdc++.h>
using namespace std;
long a[200005];
char c[200005];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	unsigned long long ans=0;
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<r) {
		if(c[l]!=c[r]) {
			ans+=min(a[l],a[r]);
		}
		if(a[l]==a[r]) {
			l++;
			r--;
		} else {
			if(a[l]>a[r]) {
				a[l]=a[l]-a[r];
				r--;
			} else {
				if(a[l]<a[r]) {
					a[r]=a[r]-a[l];
					l++;
				}

			}
		}
	}
	cout<<ans;
	return 0;
}

