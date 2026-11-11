#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[5000005],ans=0;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--) {
		long long x=m,cnt=1;
		for(int j=i-1;j>=1;j--) {
			if(x<a[i]-a[j]) break;
			x-=(a[i]-a[j]);
			cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
} 
