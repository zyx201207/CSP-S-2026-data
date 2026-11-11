#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a!=c)cout<<"0000";
	else if(b.substr(0,2)!=d.substr(0,2))cout<<"1000";
	else if((b[2]<='C'&&d[2]>'C')||(d[2]<='C'&&b[2]>'C'))cout<<"1100";
	else if((b[2]=='A'&&d[2]=='C')||(d[2]=='A'&&b[2]=='C'))cout<<"1110";
	else cout<<"1111";
	return 0;
}
