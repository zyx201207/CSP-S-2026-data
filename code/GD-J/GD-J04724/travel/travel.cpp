#include<iostream>
#include<string>
using namespace std;
string c1,s1,c2,s2;
bool f1,f2,f3;
 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){cout<<1;f1=true;}
	else{cout<<0;}
	if((s1.substr(0,2)==s2.substr(0,2))&& f1){cout<<1;f2=true;}
	else{cout<<0;}
	if(((s1.at(2)=='A'&&s2.at(2)=='B') ||
	   (s1.at(2)=='A'&&s2.at(2)=='C')  ||
	   (s1.at(2)=='B'&&s2.at(2)=='A')  ||
	   (s1.at(2)=='B'&&s2.at(2)=='C')  ||
	   (s1.at(2)=='C'&&s2.at(2)=='A')  ||
	   (s1.at(2)=='C'&&s2.at(2)=='B')  ||
	   (s1.at(2)=='D'&&s2.at(2)=='F')  ||
	   (s1.at(2)=='F'&&s2.at(2)=='D')) && f2){cout<<1;f3=true;}
	else{cout<<0;}
	if(((s1.at(2)=='A'&&s2.at(2)=='B') ||
	   (s1.at(2)=='B'&&s2.at(2)=='A')  ||
	   (s1.at(2)=='B'&&s2.at(2)=='C')  ||
	   (s1.at(2)=='C'&&s2.at(2)=='B')  ||
	   (s1.at(2)=='D'&&s2.at(2)=='F')  ||
	   (s1.at(2)=='F'&&s2.at(2)=='D')) && f3){cout<<1;}
	else{cout<<0;}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
