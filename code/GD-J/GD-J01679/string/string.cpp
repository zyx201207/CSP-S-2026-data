#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n=0;
	cin>>n;
	vector<int> a(n,0);
	vector<long long> f(n+1,0);
	vector<char> c(n,' ');
	long long ans=0;
	int cnt=0;
	int l=0;
	for(int i=0;i<n;i++) {
		cin>>a[i]>>c[i];
		l+=a[i];
	}
	for(int i=1;i<=n;i++) {
		f[i]=a[i-1]+f[i-1];
	}
	
	for(int i=0,j=n-1;i<n,j>=0;) {
		if(f[j+1]-f[i+1]<0) break;
		if(a[i]==a[j]) {
			if(c[i]!=c[j]) {
				ans+=a[j];
			}
			i++,j--;
		} else {
			if(c[i]!=c[j]) {
				int mn=min(a[i],a[j]);
				int mx=max(a[i],a[j]);
				ans+=mn;
				cnt=mx-mn;
				if(a[i]>a[j]) {
					a[i]-=mn;
					f[i+1]-=mn;
					j--;
				} else {
					a[j]-=mn;
					i++;
				}
			} else {
				int mn=min(a[i],a[j]);
				int mx=max(a[i],a[j]);
				cnt=mx-mn;
				if(a[i]>a[j]) {
					a[i]-=mn;
					f[i+1]-=mn;
					j--;
				} else {
					a[j]-=mn;
					i++;
				}
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
