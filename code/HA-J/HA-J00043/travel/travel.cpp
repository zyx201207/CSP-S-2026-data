#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	string a;
	if(c1==c2) a+='1';
	else  a+= '0';
	if(s1.substr(0,2)==s2.substr(0,2)) a+='1'; 
	else a+='0';
	a+='1';
	if(('s2.substr(2,3)-1')=='s1.substr(2,3)')a+='1'; 
	else if (('s1.substr(2,3)-1')=='s2.substr(2,3)')a+='1'; 
	else a+='0';
	cout<<a;
	
	return 0;	
}
