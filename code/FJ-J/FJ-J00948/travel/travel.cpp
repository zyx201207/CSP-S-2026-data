#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1){
		cout<<"1";
	}
	else {
		cout<<"0000";
		return 0;
	}
	if(c2[0]==s2[0]&&c2[1]==s2[1]){
		cout<<"1";
	}
	else{cout<<"000";
	return 0; 
	}
	if((c2[2]=='D'&&s2[2]=='F')||(c2[2]=='F'&&s2[2]=='D')){
		cout<<"11";
		return 0;
	}
	if((c2[2]=='A'&&s2[2]=='C')||(c2[2]=='C'&&s2[2]=='A')){
		cout<<"10";
		return 0;
	}
	if((c2[2]=='A'&&s2[2]=='B')||(c2[2]=='B'&&s2[2]=='A')){
		cout<<"11";
		return 0;
	}
	if((c2[2]=='B'&&s2[2]=='C')||(c2[2]=='C'&&s2[2]=='B')){
		cout<<"11";
		return 0;
	}
	cout<<"00";
	return 0;
}
