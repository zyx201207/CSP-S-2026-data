#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005],ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (long long i=1;i<=n;i++) cin >>a[i];
	sort(a+1,a+n+1);
	for (long long i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	long long l=1,r=n;
	while (l<=r){
		long long mid=l+(r-l)/2;
		if (a[mid]*mid-s[mid]<=m) {
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}
	cout<<ans;
	return 0;
}
