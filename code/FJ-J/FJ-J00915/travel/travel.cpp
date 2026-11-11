#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	string c1,s1,c2,s2;
	int num1=0,num2=0;
	
	cin>>c1>>s1>>c2>>s2;
	num1=(s1[0]-'0')*10+s1[1]-'0';
	num2=(s2[0]-'0')*10+s2[1]-'0';
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(num1==num2){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if((s1[2]=='F'&&s2[2]=='D')||(s2[2]=='F'&&s1[2]=='D')){
		cout<<"11";
	}else if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
		cout<<"1";
		if((s1[2]=='A'&&s2[2]=='B')||(s2[2]=='A'&&s1[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s2[2]=='B'&&s1[2]=='C')){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}else{
		cout<<"00";
		return 0;
	}
	return 0;
}
