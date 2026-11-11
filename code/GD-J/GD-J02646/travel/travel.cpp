#include<bits/stdc++.h>
using namespace std;

char c1,c2;
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	c1=s2[2];
	c2=s4[2];
	s2=s2.substr(0,2);
	s4=s4.substr(0,2);
	if(s1==s3) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(s2==s4) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if((c1<='C' && c1>='A' && c2<='C' && c2>='A') || (c1<='E' && c1>='D' && c2<='E' && c2>='D'))cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(c1-c2==1 || c2-c1==1) cout<<1;
	else{
		cout<<"0";
	}
	return 0;
}
