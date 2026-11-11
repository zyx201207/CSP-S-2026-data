#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	//cout<<s1[0]<<s1[1]<<" "<<s2[0]<<s2[1]<<endl;
	if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		cout<<"1000";
		return 0;
	}
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
		s1[3]='L';
	}
	else{
		s1[3]='R';
	}
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
		s2[3]='L';
	}
	else{
		s2[3]='R';
	}
	if(s1[3]!=s2[3]){
		cout<<"1100";
		return 0;
	}
	if(abs(s1[2]-s2[2])!=1){
		cout<<"1110";
		return 0;
	}
	else{
		cout<<"1111";
	}
}
