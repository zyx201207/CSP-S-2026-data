#include<bits/stdc++.h>;
using namespace std;

int main() 
{
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c) cout<<"1";{
		if(a!=c) {
			cout<<"0"<<"0"<<"0"<<"0";
			return 0;
		}
		if(a==c && int(b[0]-'0')*10+int(b[1]-'0') == int(d[0]-'0')*10+int(d[1]-'0')) cout<<"1";
		else cout<<"0";  //queation
		if(a==c && (b[2]<='C' && d[2]<='C') || (b[2]>='D' && d[2]>='D') )
		{
			cout<<"1";
		} 
		else cout<<"0";  //over heree
	
		if((b[2]<='C' && d[2]>='D') || (b[2]>='D' && d[2]<='C')) 
		{
			cout<<"0";
		}
		else if((b[2]-1)==d[2] || (b[2]+1)==d[2])
		{
			cout<<"1";
		}
		else cout<<"0";
		}
	return 0;
}
