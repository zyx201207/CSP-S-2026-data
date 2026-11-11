#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
typedef long long ll;

ll n,m,a[N],sum[N],l,r,mid,ans,x,y;
ll L(ll l,ll r){
	return (r-l+1)*a[r];
}
ll S(ll l,ll r){
	return sum[r]-sum[l-1];
}
ll W(ll l,ll r){
	return L(l,r)-S(l,r);
}
void Ok(ll p){
	l=1,r=p;
	while(l<=r){
		mid=(l+r)/2;
//		print("W{%d,%d,%d}=%d\n",l,mid,r,W(mid,p));
		if(W(mid,p)<=m)ans=max(ans,p-mid+1),r=mid-1;
		else l=mid+1;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;++i)sum[i]=sum[i-1]+a[i];
	for(ll i=1;i<=n;++i){
		if(a[i]!=a[i+1])
		Ok(i);
	}
	cout<<ans<<endl;
	return 0;
}

/*
5 5
1 2 4 8 9

*/
/*
5 8
-3 -1 2 2 7

*/
