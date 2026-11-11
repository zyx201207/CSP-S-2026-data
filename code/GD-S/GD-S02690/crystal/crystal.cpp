#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N];
int n,m;
bool check(int k) {
	int cnt=0;
	for(int i=1;i<=n;i++) {
		if(a[i]>k) break;
		if(cnt>m) break;
		cnt+=k-a[i]; 
	}
	return cnt<=m;
}
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=1e18;
	while(l<=r) {
		int mid=(l+r)/2;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	l--;
	int ans=0,cnt=0;
	for(int i=1;i<=n;i++) {
		if(a[i]>l) break;
		if(cnt>m) break;
		cnt+=l-a[i]; 
		ans++;
	}
	cout<<ans;
	return 0;
}
//Oct31==Dec25?
