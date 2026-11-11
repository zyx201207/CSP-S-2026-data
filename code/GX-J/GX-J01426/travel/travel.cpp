#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string s="01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17";
	string x="A,B,C,D,F";
	if(c1==c2){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(s1==s2||s1==s+"A&&B&&C"&&s2==s+"A&&B&&C"&&s1==s+"D&&F"&&s2==s+"D&&F"){
		cout<<"1";
	}
	else if(s1!=s2){
		cout<<"0";
	}
	if(c2==c1){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(s1==s2||s1==s+"A&&B&&C"&&s2==s+"A&&B&&C"&&s1==s+"D&&F"&&s2==s+"D&&F"){
		cout<<"1";
	}
	else if(s1!=s2){
		cout<<"0";
	}
	return 0;
}
