#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a!=c)cout<<0;
	else cout<<1;
	string temp1=b.substr(0,2);
	string temp2=d.substr(0,2);
	if(a!=c||temp1!=temp2)cout<<0;
	else cout<<1;
	char temp3=b[2];
	char temp4=d[2];
	if(a!=c||temp1!=temp2||(temp3>='D'&&temp4<='C')||(temp4>='D'&&temp3<='C'))cout<<0;
	else cout<<1;
	if(a!=c||temp1!=temp2||(temp3>='D'&&temp4<='C')||(temp4>='D'&&temp3<='C')||(abs((int)(temp3-temp4))!=1))cout<<0;
	else cout<<1;
	return 0;
}
