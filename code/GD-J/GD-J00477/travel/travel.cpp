#include<bits/stdc++.h>
#define ll long long
using namespace std;
string c1,s1,c2,s2;
bool f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(s1[2]<='C'&&s2[2]<='C'){
		if(char(s1[2]+1)==s2[2]||char(s1[2]-1)==s2[2]){
			f=1;
		}
		else f=0;
	}
	else if(s1[2]>='D'&&s2[2]>='D'){
		if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
			f=1;
		}
		else f=0;
	}
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))&&f){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
} 
