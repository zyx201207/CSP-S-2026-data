#include<bits/stdc++.h>
using namespace std;
int main( ){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;

	cin>>c1>>s1>>c2>>s2;
	int b1=s1[0]*10+s1[1];
	int b2=s2[0]*10+s2[1];
	if(c1!=c2){
		cout<<"0000";
	}
	else if(b1!=b2){
		cout<<"1000";		
	}
	else if((s1[2]<='C'&&s2[2]>'C')||(s1[2]>'C'&&s2[2]<='C')){
		cout<<"1100";
	}
	else if((s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A')){
		cout<<"1110";
	}
	else cout<<"1111";
	return 0;
}
