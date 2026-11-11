#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,s,a[500005],maxn=-1e18,minn=1e18;
ll check(ll k){
	ll s=0,ss=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=k){
			s+=(k-a[i]);
			ss++;
		}
	}
	if(s>m){
		return 0;
	}
	return ss;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		minn=min(minn,a[i]);
	}
	ll l=minn,r=maxn;
	while(l<=r){
		ll mid=(l+r)/2;
		if(check(mid)){
			s=check(mid);
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<s;
	return 0;
} 
