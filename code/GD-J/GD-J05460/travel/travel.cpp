#include<bits/stdc++.h>
using namespace std;
int main(){
	int c1,c2;
	int s1[3],s2[3];
	cin>>c1>>s1[0]>>c2>>s2[0];
	
	if(c1=c2){
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		if(s1[2]=="D"&&s2[2]=="F"||s1[2]=="F"&&s2[2]=="D"||s1[2]!="F"&&s2[2]!="D"||s1[2]!="D"&&s2[2]!="F"){
		
		if(s1[2]-"0"==s2[2]&&s1[2]=="D"||s1[2]==s2[2]-"0"s2[2]=="D"){
		
			cout<<"1111" 
		}
		else cout<<"1110"
	}
	else cout<<"1100"
	}
	else cout<<"1000"
	}

	else cout<<"0000";
	return 0;
}
