#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m,n;
ll a[200000+10];
bool cmp(ll x,ll y){
	return x>y;
}
ll qu(ll x){
	while(x&(x-1)){
		x=x&(x-1);
	}
	return x;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,cmp);
	ll andans=a[1];
	ll cnt=1;
	for(ll i=2;i<=n;i++){
		if(qu(andans)==qu(a[i])){
			andans&=a[i];
			cnt++;
		}else{
			andans=a[i];
			cnt=1;
		}
		if(cnt==m){
			cout<<andans;
			return 0;
		}
	}
	cout<<andans;
	return 0;
}
