#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500010],r,ans,maxx=LLONG_MIN,minn=LLONG_MAX,res,z;
bool check(ll x){
	ll t=m,tmp=0;
	for(int i=1;i<=n;i++){
		if(a[i]==x){
			tmp++;
		}
		else if(x>a[i]){
			if(t-(x-a[i])>=0){
				t-=(x-a[i]);
				tmp++;
			}
		}
	}
	if(tmp>res){
		res=tmp;
		return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		minn=min(minn,a[i]);
	}
	ll l=minn,r=maxx;
	while(l<=r){
		ll mid=(l+r)/2;
		if(check(mid)){
			r--;
		}
		else{
			l++;
		}
	}
	l=minn,r=maxx;
	while(l<=r){
		ll mid=(l+r)/2;
		if(check(mid)){
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	cout<<res; 
	return 0;
}
