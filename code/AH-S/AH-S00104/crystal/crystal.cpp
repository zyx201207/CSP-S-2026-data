#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m,a[N];
int main( ){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	ll l=1,r=n,maxn=-1;
	while(l<=r){
		ll sum=m,num=r-l+1,f=0;
		for(ll i=l;i<=r;i++) sum+=a[i];
		if(sum%num!=0){
			r--;
			f=1;
		}
		else{
			ll pjs=sum/num;
			for(ll i=l;i<=r;i++){
				if(a[i]<pjs){
					r--;
					f=1;
				}
			}
		}
		if(f==0) maxn=max(maxn,num);
		cout<<maxn<<endl;
	}
	cout<<maxn-1;
	return 0;
}
