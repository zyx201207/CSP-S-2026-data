#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=6e5+7;
int a[N],n,m,sum;
bool check(int k){
	int s=0;
	for(int i=n-k+1;i<=n;i++)s+=a[n]-a[i];
	if(s<=m)return 1;
	for(int i=n-1;i>=k;i--){
		s-=(a[i+1]-a[i])*(k-1);
		s+=a[i]-a[i-k+1];
		if(s<=m)return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n==1){cout<<1;return 0;}
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=n,ans=1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
