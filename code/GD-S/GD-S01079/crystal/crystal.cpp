#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+3;
ll n,m,a[N];
bool ck(int k){
	ll s=0,res=2*m;
	for(int i=1;i<=n;i++){
		s+=min(i-1,k)*(a[i]-a[i-1]);
		if(i>k)s-=a[i]-a[i-k];
		if(i>=k)res=min(res,s);
	}
	return res<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int l=1,r=n,ans=1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(ck(mid))l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
