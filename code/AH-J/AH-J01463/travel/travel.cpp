#include<bits/stdc++.h>
using namespace std;
bool check(char k1,char k2){
	if(k1=='A'&&k2=='B'){
		return 1;
	}if(k1=='B'&&k2=='A'){
		return 1;
	}if(k1=='B'&&k2=='C'){
		return 1;
	}if(k1=='C'&&k2=='B'){
		return 1;
	}if(k1=='A'&&k2=='C'){
		return 1;
	}if(k1=='C'&&k2=='A'){
		return 1;
	}if(k1=='D'&&k2=='F'){
		return 1;
	}if(k1=='F'&&k2=='D'){
		return 1;
	}return 0;
}bool check2(char k1,char k2){
	if(k1=='A'&&k2=='B'){
		return 1;
	}if(k1=='B'&&k2=='A'){
		return 1;
	}if(k1=='B'&&k2=='C'){
		return 1;
	}if(k1=='C'&&k2=='B'){
		return 1;
	}if(k1=='D'&&k2=='F'){
		return 1;
	}if(k1=='F'&&k2=='D'){
		return 1;
	}return 0;
}
string s1,s2,c1,c2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}else if(c1==c2&&(s1[0]!=s2[0]||s1[1]!=s2[1])){
		cout<<"1000";
	}else if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&(!check(s1[2],s2[2]))){
		cout<<"1100";
	}else if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&(check(s1[2],s2[2])&&(!check2(s1[2],s2[2])))){
		cout<<"1110";
	}else{
		cout<<"1111";
	}
	return 0;
}
