#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2; 
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2&&s1[1]==s2[1]&&s1[2]==s2[2]&&s1[3]=='A'&&s2[3]=='B'||s1[3]=='B'&&s2[3]=='C'||s1[3]=='D'&&s2[3]=='E'){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	for(int i=1;i<s1.size()-1;i++){
		if(s1[i]==s2[i]){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}
	if(s1[3]>='A'&&s1[3]<='C'&&s2[3]>='A'&&s2[3]<='C'||s1[3]>='D'&&s1[3]<='E'&&s2[3]>='D'&&s2[3]<='E'){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if(s1[3]=='A'&&s2[3]=='B'||s1[3]=='B'&&s2[3]=='C'||s1[3]=='D'&&s2[3]=='E'||s1[3]=='B'&&s2[3]=='A'||s1[3]=='C'&&s2[3]=='B'||s1[3]=='E'&&s2[3]=='D'){
		cout<<"1";
	}else{
		cout<<"0";
	}
}
