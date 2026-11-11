#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1[0]==b1[0]&&a1[1]==b1[1])cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	if(a2[0]==b2[0]&&a2[1]==b2[1])cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if('F'>=b2[2]&&b2[2]>='D'&&'F'>=a2[2]&&a2[2]>='D'){
		cout<<"11";return 0;
	}
	else if('C'>=b2[2]&&b2[2]>='A'&&'C'>=a2[2]&&a2[2]>='A'){
		cout<<"1";
	}
	else{
		cout<<"00";
		return 0;
	}
	if(abs(b2[2]-a2[2])==1)cout<<"1";
	else cout<<"0";
	return 0;
} 
