#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,ans;
long long m,a[N],t[N];
bool check(int x) {
	long long minn=1e18;
	for(int i=x; i<=n; i++) {
		long long sum=x*a[i]-t[i]+t[i-x];
		minn=min(minn,sum);
	}
	return minn<=m;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) t[i]=t[i-1]+a[i];
	int l=1,r=n;
	while(l<=r) {
		int mid=(l+r)>>1;
		if(check(mid)) {
			ans=mid;
			l=mid+1;
		} else r=mid-1;
	}
	cout<<ans;
	return 0;
}
