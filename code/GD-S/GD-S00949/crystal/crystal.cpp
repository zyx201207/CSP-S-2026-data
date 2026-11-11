#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int N=5e5+5;

ll n;
ll m;
ll a[N];
ll s[N];

ll to(ll l,ll r){
	return s[r]-s[l-1];
}
ll get(ll l,ll r){// get average
    if(to(l,r)>0)return 1LL*( to(l,r) + ((r-l+1)/2) ) / (r-l+1);
    else return 1LL*( to(l,r) - ((r-l+1)>>1) ) / (r-l+1);
	//get 4 floor 5 ceil
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n;
	cin>>m;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		//cout<<s[i]<<" ";
	}

	ll l=1,r=1,pos=1;
	ll ans=1;
	while(r<=n){
		ll mid=(l+r)/2;
		ll avr=a[mid];
		ll pos=mid;
		ll left=1LL*(pos-l)*avr- to(l,pos-1);
		ll right=to(pos,r)-1LL*(r-pos+1)*avr;
		//cout<<l<<" "<<r<<" "<<pos<<" "<<avr<<" "<<left<<" "<<right<<"\n";
		if(left+right<=m){
			ans=max(ans,r-l+1);
			r++;
		}else{
			l++;
		}
		
	}
	cout<<ans;
	
}
