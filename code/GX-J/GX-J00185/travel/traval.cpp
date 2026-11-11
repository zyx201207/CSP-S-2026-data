#include<iostream>
#include<string>
using namespace std; 
int main(){
	freopen("traval.in","r",stdin);
	freopen("traval.out","w",stdout);
	string c1,s1,c2,s2;
	bool e1,e2,e3,e4;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){e1=1;}else{cout<<"0000";return 0;}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){e2=1;}else{cout<<"1000";return 0;}
	if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')){e3=1;}else{cout<<"1100";return 0;}
	if((s1[2]=='F'&&s2[2]=='D')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='A'&&s2[2]=='B')){e4=1;}else{cout<<"1110";return 0;}
	cout<<e1<<e2<<e3<<e4;
}
