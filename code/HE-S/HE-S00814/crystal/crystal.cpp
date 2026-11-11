#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m;
int a[N],sum[N];
inline bool check(int mid){
	for(int i=1;i+mid-1<=n;i++){
		int j=i+mid-1;
		if(sum[j]-sum[i-1]+m>=a[j]*mid)	return true;
	}
	return false;
}
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++)	cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)	sum[i]=sum[i-1]+a[i];
//	for(int i=1;i<=n;i++)	cout<<sum[i]<<' ';
	int l=0,r=n,mid;
	while(l<=r) {
		mid=l+r>>1;
//		cout<<mid<<' ';
		if(check(mid))	l=mid+1;
		else r=mid-1;
	}
	cout<<r;
	return 0;
}
/*
5 5
2 1 2 4 8 9

*/
