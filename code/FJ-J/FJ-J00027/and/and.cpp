#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n,m;
struct num{
	ll t;
	ll y;
};
num a[200005];
bool cmp(num aa,num bb){
	if(aa.y>bb.y) return true;
	if(aa.y==bb.y) return aa.t>bb.t;
	return false;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=0;i<n;i++){
		cin>>a[i].t;
		ll c=0,b=a[i].t;
		while(b!=0){
			b&=b-1;
			c+=1;
		}
		a[i].y=c;
	}
	sort(a,a+n,cmp);
	ll ans=a[0].t;
	for(ll i=1;i<m;i++){
	    ans&=a[i].t;
	}
	cout<<ans<<endl;
    return 0;
}
