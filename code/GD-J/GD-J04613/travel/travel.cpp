#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("trevel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2)cout<<1;
	else return cout<<"0000",0;
	
	string ss1=s1.substr(0,2),ss2=s2.substr(0,2);
	if(ss1==ss2)cout<<1;
	else return cout<<"000",0;
	
	char i=s1[2],j=s2[2];
	if((i<='C'&&j<='C')||(i>='D'&&j>='D'))cout<<1;
	else return cout<<"00",0;
	
	if(abs(i-j)==1)cout<<1;
	else cout<<0;
	return 0;
} 
