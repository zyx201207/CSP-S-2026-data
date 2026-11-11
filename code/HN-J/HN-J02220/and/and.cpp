#include<bits/stdc++.h>
using namespace std;
int const N=2e5+5;
long long n,m,a[N],mx;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		long long ans=a[i] and a[i-1];
		mx=max(mx, ans);
	}
	cout<<mx;
	return 0;
}

