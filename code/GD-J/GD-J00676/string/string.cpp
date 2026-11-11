#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0;
	cin>>n;
	vector<long long> a(n);
	vector<char> c(n);
	for(long long i=0; i<n; i++) cin>>a[i]>>c[i];
	for(long long i=1; i<n; i++) {
		if(c[i]==c[i-1]) a[i]=a[i-1]+a[i],a[i-1]=0;
	}
	for(long long i=0,j=n-1; i<=j&&i<n&&j>0;) {
		if(a[i]==0) i++;
		if(a[j]==0) j--;
		if(c[i]!=c[j]) {
			if(a[i]==a[j]) ans+=a[i],i++,j--;
			else {
				if(a[i]<a[j]) {
					ans+=a[i];
					a[j]-=a[i];
					a[i]=0;
				} else {
					ans+=a[j];
					a[i]-=a[j];
					a[j]=0;
				}
			}
		} else {
			if(a[i]==a[j]) i++,j--;
			else {
				if(a[i]<a[j]) {
					a[j]-=a[i];
					a[i]=0;
				} else {
					a[i]-=a[j];
					a[j]=0;
				}
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}

