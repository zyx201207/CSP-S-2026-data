#include <bits/stdc++.h> 
using namespace std;
#define int long long
int n,m,a[500008],ans,t,sum,wh,l;
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	l=1;		
	for(int i=2;i<=n;i++) {
		sum+=(a[i]-a[i-1])*(i-l);
		while(sum>m&&l<i) {
			sum-=(a[i]-a[l]);
			l++;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
/*
5 15
-10 1 2 3 4 
*/
