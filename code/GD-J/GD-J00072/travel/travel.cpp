#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2; 
bool f3(string s1,string s2){
	if((s1[2]<='C'&&s1[2]>='A')&&(s2[2]<='C'&&s2[2]>='A')) return true;
	else if((s1[2]=='D'&&s2[2]=='F') || s1[2]=='F'&&s2[2]=='D') return true;
	else return false;
}
bool f4(string s1,string s2){
	if((s1[2]=='D'&&s2[2]=='F') || s1[2]=='F'&&s2[2]=='D') return true;
	else if(s1[2]+1==s2[2]||s1[2]-1==s2[2]) return true;
	else return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	
	if(c1==c2&&s1.substr(0,2)==s2.substr(0,2)){
		cout<<1;
	}else{
		cout<<0;
	}

	if(c1==c2&&s1.substr(0,2)==s2.substr(0,2)&&f3(s1,s2)){
		cout<<1;
	}else{
		cout<<0;
	}

	if(c1==c2&&s1.substr(0,2)==s2.substr(0,2)&&f3(s1,s2)&&f4(s1,s2)){
		cout<<1;
	}else{
		cout<<0;
	}

    return 0;
}
