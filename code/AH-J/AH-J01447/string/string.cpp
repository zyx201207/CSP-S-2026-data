#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	ll p;
	char c;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;cin>>n;
	vector<node> a(n+1);
	ll k=0;
	for(ll i=1;i<=n;i++){
        cin>>a[i].p>>a[i].c;
        k+=a[i].p;
	}
	ll n2=0;
	if(k&1) n2=k/2+1;
	else n2=k/2;
	ll id=0;
	for(ll i=1;i<=n;i++){
		n2-=a[i].p;
		if(n2<=0){
			id=i;
			n2=abs(n2);
			break;
		}
	}
	vector<node> lt;
	vector<node> rt;
	if(n&1){
		for(ll i=1;i<=id-1;i++) lt.push_back({a[i].p,a[i].c});
		lt.push_back({a[id].p-n2,a[id].c});
		for(ll i=n;i>=id+1;i--) rt.push_back({a[i].p,a[i].c});
		if(n2-1>=1) rt.push_back({n2-1,a[id].c});
	}else{
		for(ll i=1;i<=id-1;i++){
			lt.push_back({a[i].p,a[i].c});
		}
		lt.push_back({a[id].p-n2,a[id].c});
		for(ll i=n;i>=id+1;i--) rt.push_back({a[i].p,a[i].c});
		if(n2>=1) rt.push_back({n2,a[id].c});
	}
	ll sum=0,lti=1,rti=1,ltl=lt.size(),rtl=rt.size();
	node ltp=lt[0],rtp=rt[0];
	while(lti<=ltl||rti<=rtl){
		ll o=min(ltp.p,rtp.p);
		if(ltp.c!=rtp.c) sum+=o;
		ltp.p-=o;
		rtp.p-=o;
		if(ltp.p==0) ltp=lt[lti++];
		if(rtp.p==0) rtp=rt[rti++];
	}cout<<sum;
	return 0;
}
