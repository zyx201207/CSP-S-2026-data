#include<bits/stdc++.h>
using namespace std;

string s11,s1,s22,s2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.ans","w",stdout);

	cin>>s11>>s1;
	cin>>s22>>s2;
	
	if(s11==s22){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}		
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}else{
		cout<<"000";
	}
	char a=s1[2],b=s2[2];
	if((a=='A'&&b=='B')||(a=='B'&&b=='A')){
		cout<<"11";
		return 0;
	}else if((a=='B'&&b=='C')||(a=='C'&&b=='B')){
		cout<<"11";	
		return 0;
	}else if((a=='D'&&b=='F')||(a=='F'&&b=='D')){
		cout<<"11";
		return 0;
	}else 	if((a=='A'&&b=='C')||(a=='C'&&b=='A')){
		cout<<"10";	
		return 0;
	}
	cout<<"00";
	return 0;
}
