#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,m,a[N],b[N];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	if(n==m) {
		long long ans=a[1];
		for(int i=2; i<=n; i++) {
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==1) {
		long long big=0;
		for(int i=1; i<=n; i++) {
			big=max(big,a[i]);
		}
		cout<<big;
		return 0;
	}
	if(m==2) {
		for(int i=1; i<n; i++) {
			long long tmp;
			for(int j=i; j<=n; j++) {
				tmp=a[i]&a[i+1];
				b[i]=max(b[i],tmp);
			}
		}
		sort(b+1,b+n);
		cout<<b[n-1];
		return 0;
	}
	if(m==n-1) {
		for(int i=1; i<n; i++) {
			long long tmp;
			for(int j=i; j<=n; j++) {
				tmp=a[i]&a[i+1];
				b[i]=max(b[i],tmp);
			}
		}
		sort(b+1,b+n);
		long long ans=b[2];
		for(int i=3; i<n; i++) {
			ans&=b[i];
		}
		cout<<ans;
		return 0;
	}
	cout<<0;
	return 0;
}
