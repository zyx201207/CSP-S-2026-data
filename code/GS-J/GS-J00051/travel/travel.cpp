#include<bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
bool ce(string a,string b){
	if((a=="D"&&b=="F")||(a=="F"&&b=="D"))return 1;
	else if((a=="A"&&b=="B")||(a=="B"&&b=="C")||(a=="A"&&b=="C"))return 1;
	else if((a=="B"&&b=="A")||(a=="C"&&b=="B")||(a=="C"&&b=="A"))return 1;
	else return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	bool f=0,ff=0,fff=0;
	if(c==cc){
		f=1;cout<<f;
	}else{
		cout<<0;
	}
	string g=s.substr(0,2),h=ss.substr(0,2);
	if(g==h&&f){
		ff=1;cout<<ff;
	}else{
		cout<<0;
	}
	string a=s.substr(2),b=ss.substr(2);
	if(ce(a,b)&&f&&ff){
		fff=1;cout<<fff;
	}else{
		cout<<0;
	}
	int d,e;
	for(int i=0;i<a.length();i++)d=a[i]-'0';
	for(int i=0;i<b.length();i++)e=b[i]-'0';
	if(abs(d-e)==1&&a!="C"&&b!="D"&&a!="D"&&b!="C"&&f&&ff&&fff){
		cout<<1;
	}else if(((a=="D"&&b=="F")||(a=="F"&&b=="D"))&&f&&ff&&fff){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
