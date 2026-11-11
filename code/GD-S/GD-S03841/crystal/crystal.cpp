#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll m,a[501000],l=LLONG_MAX,r=LLONG_MIN;
bool ck(ll x){
	ll s=0,mi;
	for(int i=1;i<=x;i++){
		s+=a[x]-a[i];
	}
	mi=s;
	for(int i=2;i+x-1<=n;i++){
		int j=i+x-1;
		s-=a[j-1]-a[i-1];
		s+=(a[j]-a[j-1])*x;
		mi=min(mi,s); 
	}
	return mi<=m;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		l=min(l,a[i]);
		r=max(r,a[i]);
	}
	sort(a+1,a+n+1);
	l=1,r=n;
	while(l<=r){
		ll mid=l+(r-l)/2;
		if(ck(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<r;
	return 0;
} 

