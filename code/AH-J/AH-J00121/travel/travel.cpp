#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ll a1,a2,b1,b2;
	char c1,c2;
	scanf("%02lld %02lld%c %02lld %02lld%c",&a1,&b1,&c1,&a2,&b2,&c2);
	if(a1==a2) cout<<1;
	else cout<<0;
	if(a1==a2){
		if(b1==b2) cout<<1;
		else cout<<0;
		ll f=0;
		if(b1==b2){
			if(c1<='C'&&c2<='C'){cout<<1;f=1;}
			else if(c1<='F'&&'C'<c1&&c2<='F'&&'C'<c2){cout<<1;f=1;}
			else cout<<0;
		}
		else cout<<0;
		if(f){
			ll x=ll(c1)-ll(c2);
			if(abs(x)==1) cout<<1;
			else cout<<0;
		}
		else cout<<0;
	}
	else cout<<"000";
	return 0;
}
