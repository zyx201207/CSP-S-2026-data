#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	char a='A';
	char b='B';
	char c='C';
	char d='D';
	char f='F';
	char q='1';
	char w='0';
	char e='9';
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<1;
	}
	
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if(s1[2]==d||s1[2]==f){
		if(s2[2]==d||s2[2]==f){
			cout<<1;
		}
		else{
			cout<<"00";
			return 0;
		}
	}else{
		if(s2[2]==a||s2[2]==b||s2[2]==c){
			cout<<1;
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	if(s1[1]==w&&s1[0]==q){
		if((s2[1]==e&&s2[0]==w)||(s2[1]==q&&s2[0]==q)){
			cout<<1;
			return 0;
		}
	} 
	if(s2[1]==w&&s2[0]==q){
		if((s1[1]==e&&s1[0]==w)||(s1[1]==q&&s1[0]==q)){
			cout<<1;
			return 0;
		}
	} 
	if(s1[1]-s2[1]==1||s2[1]-s1[1]==1){
		cout<<1;
		return 0;
	}
	else{
		cout<<0;
	}
    return 0;
}
