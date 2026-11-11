#include <iostream>
#include <string>
using namespace std;
char s11[2],s12, s21[2],s22;
string c1, c2;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin>>c1>>s11[0]>>s11[1]>>s12>>c2>>s21[0]>>s21[1]>>s22;
	
	if(c1==c2) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	
	if(s11[0]==s21[0] && s11[1]==s21[1]) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	
	if(s12=='A'){
		if(s22=='B') cout<<"11";
		else if(s22=='C') cout<<"10";
		else cout<<"00";
	}
	else if(s12=='B'){
		if(s22=='A' || s22=='C') cout<<"11";
		else cout<<"00";
	}
	else if(s12=='C'){
		if(s22=='B') cout<<"11";
		else if(s22=='A') cout<<"10";
		else cout<<"00";
	}
	else{
		if(s22=='D' || s22=='F') cout<<"11";
		else cout<<"00";
	}
	
	return 0;
}
