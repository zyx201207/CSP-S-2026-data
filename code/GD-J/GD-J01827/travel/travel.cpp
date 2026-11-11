#include<iostream> 
using namespace std;
int main(){
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	else cout<<0;
	if(s1[0]==s2[0]&&s1[1]==s2[1])cout<<1;
	else cout<<0;
	char a=s1[2],b=s2[2];
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		if((a-b=1||b-a=1)&&(a=='C'&&b!='D')&&(b=='C'&&a!='D'))cout<<11;
		else if(((a=='A'||a=='B'||a=='C')&&(b!='D'||b!='E'))&&((b=='A'||b=='B'||b=='C')&&(a!='D'||a!='E')))cout<<10;
		else cout<<00;
	}
	return 0;
}
