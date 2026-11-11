#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N];
bool check(int mid){
	int k=m,cnt=0,jz=a[upper_bound(a+1,a+1+n,mid)-a];
	for(int i=1;i<=n;i++)
		if(jz<=a[i]&&k-(jz-a[i])>=0)k-=(jz-a[i]),cnt++;
	return cnt>=mid;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int l=0,r=n,ans=0,mid=0;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid))l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans+abs(n-m);
	return 0;
}
