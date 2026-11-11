#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c) cout<<1;
	else cout<<0;
	
	if(a==c&&b[0]==d[0]&&b[1]==d[1]) cout<<1;
	else cout<<0;
	
	if(a==c&&b[0]==d[0]&&b[1]==d[1]&&b[2]<='C'&&d[2]<='C') cout<<1;
	else if(a==c&&b[0]==d[0]&&b[1]==d[1]&&b[2]>'C'&&d[2]>'C') cout<<1;
	else cout<<0;
	
	if(b[2]=='C'&&d[2]=='D') cout<<0;
	else if(b[2]=='D'&&d[2]=='C') cout<<0;
	else if(a==c&&b[0]==d[0]&&b[1]==d[1]&&abs((int)b[2]-(int)d[2])==1) cout<<1;
	else cout<<0;
	
	return 0;
}
