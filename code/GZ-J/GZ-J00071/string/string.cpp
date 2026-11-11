//GZ-J00071 张世铠 贵阳市白云区华师一学校 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005];
char c[200005];
ll rp[200005];
ll n,len=0;
ll ppp(ll m){
	if(m==len){
		return n;
	}
	ll ans=(upper_bound(rp+1,rp+n,m)-rp);
	if(rp[ans-1]==m){
		return ans-1; 
	}
	else{
		return ans;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
		rp[i]=a[i]+rp[i-1];
	}
	ll ans=0;
	ll l=1,r=len;
	while(l<=(len+1)/2 && r>(len+1)/2){
		ll pl=ppp(l),pr=ppp(r);
		if(c[pl]==c[pr]){
			ll dl=max(min(rp[pl],(len+1)/2)-l,1LL),dr=max(r-max(rp[pr-1],(len+1)/2),1LL);
			l+=min(dl,dr);
			r-=min(dl,dr);
		}
		else{
			ll dl=max(min(rp[pl],(len+1)/2)-l,1LL),dr=max(r-max(rp[pr-1],(len+1)/2),1LL);
			l+=min(dl,dr);
			r-=min(dl,dr);
			ans+=min(dl,dr);
		}
	}
	cout<<ans;
	return 0;
}
