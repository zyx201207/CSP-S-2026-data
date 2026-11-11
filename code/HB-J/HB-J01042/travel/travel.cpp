#include <bits/stdc++.h>
using namespace std;
char side1[3]={'A','B','C'},side2[2]={'D','F'};
bool id(char s1pos,char s2pos){
	int id1=-1,id2=-1;
	for(int i=0;i<3;i++){
		if(side1[i]==s1pos){
			id1=0;
		}
		if(side1[i]==s2pos){
			id2=0;
		}
	}
	for(int i=0;i<2;i++){
		if(side2[i]==s1pos){
			id1=1;
		}
		if(side2[i]==s2pos){
			id2=1;
		}
	}
	if(id1==id2){
		return true;
	}
	return false;
}
bool beside(char s1pos,char s2pos){
	if(s1pos=='A'&&s2pos=='B'){
		return true;
	}
	if(s1pos=='B'&&(s2pos=='A'||s2pos=='C')){
		return true;
	}
	if(s1pos=='C'&&(s2pos=='B'||s2pos=='D')){
		return true;
	}
	if(s1pos=='D'&&(s2pos=='E'||s2pos=='C')){
		return true;
	}
	if(s1pos=='E'&&s2pos=='D'){
		return true;
	}
	return false;
}
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		if(s1[1]==s2[1]){
			cout<<"1";
			char s1pos=s1[2],s2pos=s2[2];
			if(id(s1pos,s2pos)){
				cout<<"1";
				if(beside(s1pos,s2pos)){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
