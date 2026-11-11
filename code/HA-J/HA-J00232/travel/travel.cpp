#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c) cout<<true;
	else{
		cout<<false<<false<<false<<false;
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]) cout<<true;
	else{
		cout<<false<<false<<false;
		return 0;
	}
	if((b[2]<'D'&&d[2]<'D')||(b[2]>='D'&&d[2]>='D')) cout<<true;
	else{
		cout<<false<<false;
		return 0;
	}
	if((b[2]==d[2]-'0')&&(b[2]!='C'&&d[2]!='D')) cout<<true;
	else if((d[2]==b[2]-'0')&&(b[2]!='D'&&d[2]!='C')) cout<<true;
	else cout<<false;	
	return 0;
}
