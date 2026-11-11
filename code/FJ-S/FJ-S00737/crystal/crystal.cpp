#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500050],n,m,l=1,r;
bool check(ll x){
	if(x<=1){
		return 1;
	}
	for(int i=1;i<=n;i++){
		ll w=m,c=0;
		for(int j=i;j>=1;j--){
			int q=a[i]-a[j];
			if((w-q)<0)break;
			w-=q;
			c++;
			if(c>=x){
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	scanf("%lld%lld",&n,&m);
	r=n;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	while(l<r){
		ll mid=(l+r+1)/2;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
} 
