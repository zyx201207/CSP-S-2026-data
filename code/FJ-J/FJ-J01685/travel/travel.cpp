#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	ll x=0,y=0,flag=0;
	char q,p;
	cin>>a>>b>>c>>d;
		if(a==c) cout<<"1";
		else cout<<"0",flag=1;
	for(ll i=0; i<b.size()-1; i++) {
		if(i>='0' && i<='9') y=y*10+(b[i]-'0');
		else q=b[i];
	}
	for(ll i=0; i<d.size()-1; i++) {
		if(i>='0' && i<='9') x=x*10+(d[i]-'0');
		p=d[i];
	}
	if(flag==0) {
		if(y==x) cout<<"1";
		else cout<<"0",flag=1;
	} else cout<<"0";
	if(flag==1) cout<<"0";
	else {
		if(q<='C' && q>='A' && p<='C' && p>='A') cout<<"1";
		else if(q<='E' && q>='D' && p<='E' && p>='D') cout<<"1";
		else cout<<"0",flag=1;
	}
	if(flag==1) cout<<"0";
	else {
		if(abs(int(p)-int(q))==1) cout<<"1";
		else cout<<"0";
	}
	return 0;
}
