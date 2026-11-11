#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int n,m,a[N],q[N];
bool check(int mid){
	int mn=1e18;
	for(int i=mid;i<=n;i++)
		mn=min(mn,mid*a[i]-q[i]+q[i-mid]);
	return m>=mn;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)q[i]=q[i-1]+a[i];
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}//100pts
