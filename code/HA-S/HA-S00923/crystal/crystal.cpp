#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010];
bool check(int i) {
	long long cnt=0;
	for(int j=1; j<=i; j++)cnt+=a[i]-a[j];
	if(cnt<=m)return 1;
	for(int j=i+1; j<=n; j++) {
		cnt-=a[j-1]-a[j-i];
		cnt+=(a[j]-a[j-1])*(i-1);
		if(cnt<=m)return 1;
	}
	return 0;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long  l=1,r=n;
	while(l<r) {
		int mid=(l+r+1)/2;
		if(check(mid))
			l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}
