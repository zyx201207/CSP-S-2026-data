#include<bits/stdc++.h>
#define int long long
using namespace std;
string a,b,c,d;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	string l,r;
	l+=b[0],l+=b[1],r+=d[0],r+=d[1]; 
	if(l==r) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if((b[2]<='C'&&d[2]<='C')||(b[2]>'C'&&d[2]>'C')) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(abs(b[2]-d[2])==1) cout<<1;
	else cout<<0;
	return 0;
}
