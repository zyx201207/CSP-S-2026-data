#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
long long n,m;
bool check(long long mid) {
	long long cnt=0;
	int j=1;
	while(j+mid-1<=n) {
		for(int i=j; i<=mid+j-1; i++) {
			cnt+=(a[mid+j-1]-a[i]);
		}
		if(cnt<=m) {
			return 1;
		} else {
			j++;
		}
	}
	return 0;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long l=1,r=n+1;
	while(l<r) {
		long long mid=(l+r+1)/2;
		if(check(mid)) {
			l=mid;
		} else {
			r=mid-1;
		}
	}
	cout<<r;
	return 0;
}
