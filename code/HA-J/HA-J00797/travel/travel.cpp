#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	
	if(s1[0]==s2[0]&&s1[1]==s2[1])cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	
	if(s1[2]<='C'&&s2[2]<='C')cout<<"1";
	else if(s1[2]<='F'&&s2[2]<='F'){
		cout<<"11";
		return 0;
	}
	else{
		cout<<"00";
		return 0;
	}
	
	char s12=s1[2],s22=s2[2];
	if(s12=='B'&&s22=='A')cout<<"1";
	else if(s12=='A'&&s22=='B')cout<<"1";
	else if(s12=='B'&&s22=='C')cout<<"1";
	else if(s12=='C'&&s22=='B')cout<<"1";
	else if(s12=='C'&&s22=='D')cout<<"1";
	else if(s12=='D'&&s22=='C')cout<<"1";
	else{
		cout<<"0";
		return 0;
	}
	return 0;
}
