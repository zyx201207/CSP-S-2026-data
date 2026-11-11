#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005],vmax=1;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n>5000) {
		int f=1;
		for(int i=3;i<=n;i++) {
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]) {
				f=0;
				break;
			}
		}
		if(f==1) {
			long long sum=a[n]-a[n-1];
			int i=n-2;
			for(;i>=1;i--) {
				if(sum+a[n]-a[i]>m) {
					vmax=n-i;
					break;
				}
				sum+=a[n]-a[i];
			}
			if(i==0) {
				vmax=n;
			}
			cout<<vmax;
			return 0;
		}
	}
	for(int i=n;i>vmax;i--) {
		if(a[i]-a[i-1]>m) {
			continue;
		}
		long long sum=a[i]-a[i-1];
		int j=i-2;
		for(;j>=1;j--) {
			if(sum+a[i]-a[j]>m) {
				vmax=max(vmax,(long long)(i-j));
				break;
			}
			sum+=a[i]-a[j];
		}
		if(j==0) {
			vmax=max(vmax,(long long)i);
		}
	}
	cout<<vmax;
	return 0;
}
