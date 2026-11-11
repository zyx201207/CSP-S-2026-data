#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string rn,r,x,xn;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rn>>r>>xn>>x;
	if(rn!=xn){
		cout<<"0000";
		return 0;
	}else{
		cout<<1;
		ll rt=(r[0]-'0')*10+r[1]-'0';
		ll xt=(x[0]-'0')*10+x[1]-'0';
		if(rt!=xt){
			cout<<"000";
			return 0;
		}else{
			cout<<1;
			ll r3=r[2]-'A';
			ll x3=x[2]-'A';
			if(r3>=0&&r3<=2&&x3>=0&&x3<=2){
				cout<<1;
				if(max(r3,x3)-min(r3,x3)==1) cout<<1;
				else cout<<0;
			}else if(r3>=3&&x3>=3&&max(r3,x3)-min(r3,x3)==1) cout<<11;
			else cout<<"00";
		}
	}

	return 0;
} 
