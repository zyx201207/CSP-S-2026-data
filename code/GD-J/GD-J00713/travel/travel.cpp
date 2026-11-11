#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	bool ok1=false,ok2=false,ok3=false;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		cout<<"1";
		ok1=true;
	}
	else{
		cout<<"0";
		ok1=false;
	}
	if(s1[1]==s2[1]&&s1[0]==s2[0]&&ok1){
		cout<<"1";
		ok2=true;
	}
	else{
		cout<<"0";
		ok2=false;
	}
	if(ok2&&((s1[2]<='C')==(s2[2]<='C'))){
		cout<<"1";
		ok3=true;
	}
	else{
		ok3=false;
		cout<<"0";
	}
	if(ok3&&((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C'))||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
} 
