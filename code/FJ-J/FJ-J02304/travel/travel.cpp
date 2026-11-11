#include<bits/stdc++.h>
using namespace std;
bool cx(string s1,string s2){
	int ok=1;
	int len=s1.size();
	for(int i=0;i<len;i++){
		if(s1[i]!=s2[i]) return false;
	}
	return true;
}
bool tp(string s1,string s2){
	int ok=1;
	int len=s1.size();
	for(int i=0;i<len-1;i++){
		if(s1[i]!=s2[i]) return false;
	}
	return true;
}
bool gd(string s1,string s2){
	char c1=s1[2],c2=s2[2];
	if(c1>'C'){
		if(c2<'D') return false;
		else return true;
	}
	else{
		if(c2<'D') return true;
		else return false;
	}
}
bool lz(string s1,string s2){
	char c1=s1[2],c2=s2[2],c3;
	if(c1>c2){
		c3=c1;
		c1=c2;
		c2=c3;
	}
	if(c1=='D'){
		if(c2=='F') return true;
		else return false;
	}
	if(c1<'D'){
		if(c1=='C') return false;
		else{
			if(c1+1==c2) return true;
			else return false;
		}
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(!cx(s1,s3)){
		cout<<"0000";
		return 0;
	}
	if(!tp(s2,s4)&&cx(s1,s3)){
		cout<<"1000";
		return 0;
	}
	if(!gd(s2,s4)&&tp(s2,s4)){
		cout<<"1100";
		return 0;
	}
	if(!lz(s2,s4)&&gd(s2,s4)){
		cout<<"1110";
		return 0;
	}
	if(lz(s2,s4)){
		cout<<"1111";
		return 0;
	}
	return 0;
}
