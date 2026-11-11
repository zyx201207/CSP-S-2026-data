#include<bits/stdc++.h>
using namespace std;
bool f(string a,string b){
	if(a[2]>='A' && a[2]<='C' && b[2]>='A' && b[2]<='C') return true;
	else if(a[2]>='D'&&a[2]<='F' && b[2]>='D'&&b[2]<='F') return true;
	else return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;cin>>c1>>s1>>c2>>s2;
	string ans="";
	if(c1==c2)ans=ans+"1";
	else ans=ans+"0";
	if(c1==c2 && s1.substr(0,2)==s2.substr(0,2)) ans=ans+"1";
	else ans=ans+"0";
	if(c1==c2 && s1.substr(0,2)==s2.substr(0,2) && f(s1,s2)) ans=ans+"1";
	else ans=ans+"0";
	if(c1==c2 &&  s1.substr(0,2)==s2.substr(0,2) && f(s1,s2) && abs(s1[2]-s2[2])==1) ans=ans+"1";
	else ans=ans+"0";
	cout<<ans;
	return 0;
}
