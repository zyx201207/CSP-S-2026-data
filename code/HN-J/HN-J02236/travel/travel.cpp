#include<iostream>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	else cout<<'1';
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<'1';
	}else{
		cout<<'000';
		return 0;
	}
	if(s1[2]=='D'||s1[2]=='F'){
		if(s2[2]=='D'||s2[2]=='F'){
			cout<<"11";
			return 0;
		}
		else{
			cout<<"00";
			return 0;
		}
	}else{
		if(s2[2]!='D'&&s2[2]!='F'){
			cout<<'1';
		}
		else{
			cout<<'00';
			return 0;
		}
	}
	if(s1[2]=='A'){
		if(s2[2]=='B'){
			cout<<'1';
		}
		else{
			cout<<'0';
		}
	}
	if(s1[2]=='B'){
		cout<<'1';
	}
	if(s1[2]=='C'){
		if(s2[2]=='B'){
			cout<<'1';
		}
		else{
			cout<<'0';
		}
	}
	return 0;
	
} 


 
