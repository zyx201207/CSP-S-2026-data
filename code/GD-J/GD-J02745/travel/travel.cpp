#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
long long c3,c4;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>b1>>a2>>b2;
	if(a1==a2){
		c3=(b1[0]-'0')*10+b1[1]-'0';
		c4=(b2[0]-'0')*10+b2[1]-'0';
		if(c3==c4){
			bool k1=0,k2=0;
			if(b1[2]=='A'||b1[2]=='B'||b1[2]=='C') k1=1;
			if(b2[2]=='A'||b2[2]=='B'||b2[2]=='C') k2=1;
			if(k1==k2){
				if((b1[2]=='A'&&b2[2]=='C')||(b1[2]=='C'||b2[2]=='A')) cout<<"1110";
				else cout<<"1111";
			}else cout<<"1100";
		}else cout<<"1000";
	}else cout<<"0000";
	return 0;
} 
