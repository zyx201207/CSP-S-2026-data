#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read() {
	int x;
	cin>>x;
	return x;
}
const int N=500010;
int n,m,a[N];
inline bool check(int len) {
	int sum=0;
	for(int i=1;i<len;i++) {
		sum+=(i-1)*(a[i]-a[i-1]);
	}
	for(int i=len;i<=n;i++) {
		sum+=(len-1)*(a[i]-a[i-1]);
		if(sum<=m) return 1;
		sum-=a[i]-a[i-len+1];
	}
	return 0;
}
signed main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) {
		a[i]=read();
	}
	sort(a+1,a+n+1);
	int l=1,r=n,mid,res=0;
	while(l<=r) {
		mid=(l+r)>>1;
		if(check(mid)) {
			l=mid+1;
			res=mid;
		}
		else {
			r=mid-1;
		}
	}
	cout<<res;
	return 0;
}
