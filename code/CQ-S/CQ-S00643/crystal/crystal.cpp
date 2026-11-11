#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,l,r,mid,ans;
long long m,a[N],b[N];
bool chk(int x,long long res=2e18){
	for(int ll=1,rr=x;rr<=n;++ll,++rr){
		res=min(res,1ll*x*(a[rr]-a[rr-1])-a[rr]+a[ll-1]);
	}
	return res<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		a[i]+=a[i-1];
	}
	l=2,r=n,ans=1;
	while(l<=r){
		mid=(l+r)>>1;
		chk(mid)?ans=mid,l=mid+1:r=mid-1;
	}
	cout<<ans;
	return 0;
}
