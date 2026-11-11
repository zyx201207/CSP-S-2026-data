#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+9;
int n,m,a[maxn],sum[maxn];
bool check(int mid){
	if(mid==1)return true;
	for(int i=1;i<=n-mid+1;i++){
		int ci=a[i+mid-1]*(mid-1)-(sum[i+mid-2]-sum[i-1]);
		if(ci<=m)return true;
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int l=1,r=n,mid=(l+r)/2;
	while(l<r-1){
		if(check(mid))l=mid,mid=(l+r)/2;
		else r=mid-1,mid=(l+r)/2;
	}
	if(check(r))cout<<r;
	else cout<<l;
	return 0;
}
