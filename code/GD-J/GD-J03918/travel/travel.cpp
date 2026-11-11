#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int p(char x){
	if(x<='C'&&x>='A')return 1;
	if(x<='F'&&x>='D')return 2;
	else return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	else cout<<0;
	
	if(s1.substr(0,2)==s2.substr(0,2)&&c1==c2)cout<<1;
	else cout<<0;
	
	char t1=s1[2],t2=s2[2];
	if(c1==c2&&p(t1)==p(t2)&&s1.substr(0,2)==s2.substr(0,2))cout<<1;
	else cout<<0;
	
	if(c1==c2&&abs(t1-t2)==1&&p(t1)==p(t2)&&s1.substr(0,2)==s2.substr(0,2))cout<<1;
	else cout<<0;
	return 0; 
}
