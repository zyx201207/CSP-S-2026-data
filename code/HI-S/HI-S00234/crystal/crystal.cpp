#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
using ll=long long;
ll s[N],a[N],m,n;
bool check(int mid,int x){
	ll sum=s[x]-s[mid-1];
//	cout<<a[mid]*(x-mid+1)-sum<<'\n';
	if(a[x]*(x-mid+1)-sum<=m)
		return 1;
	else 
		return 0;
}
int fid(int x){
	int l=1,r=x;
	int ret=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid,x)){
			ret=x-mid+1;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	return ret;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
//		cout<<fid(i)<<'\n';
		ans=max(ans,fid(i));
	}
//	cout<<check(1,5);
	cout<<ans;
	return 0;
} 
