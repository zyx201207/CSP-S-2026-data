#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n,l,r,ans=0;
	cin >> n;
	vector<long long> a(n);
	vector<char> c(n);
	for(int i=0;i<n;i++) {
		cin >> a[i] >> c[i];
	}
	for(l=0,r=n-1;l<r;) {
		if(c[l]==c[r]) {
			if(a[l]==a[r]) {
				l++;
				r--;
				continue;
			}
			if(a[l]>a[r]) {
				a[l]-=a[r];
				r--;
				continue;
			}else{
				a[r]-=a[l];
				l++;
				continue;
			}
		}
		if(a[l]==a[r]) {
			ans+=a[l];
			l++;
			r--;
			continue;
		}
		if(a[l]>a[r]) {
			ans+=a[r];
			a[l]-=a[r];
			r--;
			continue;
		}else{
			ans+=a[l];
			a[r]-=a[l];
			l++;
			continue;
		}
	}
	cout << ans;
	return 0;
} 
