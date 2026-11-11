#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool ce(char a,char b){
	if(a=='A'||a=='B'||a=='C'){
		if(b=='D'||b=='F'){
			return false;
		}
	}
	if(b=='A'||b=='B'||b=='C'){
		if(a=='D'||a=='F'){
			return false;
		}
	}
	return true;
}
bool lin(char a,char b){
	if(a=='A'&&b=='C'){
		return false;
	}
	if(a=='C'&&b=='A'){
		return false;
	}
	return true;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(c1==c2 && s1[0]==s2[0]&& s1[1]==s2[1]){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(c1==c2 && s1[0]==s2[0] && s1[1]==s2[1] && ce(s1[2],s2[2]) ){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(c1==c2 && s1[0]==s2[0] && s1[1]==s2[1] && ce(s1[2],s2[2]) && lin(s1[2],s2[2])){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
