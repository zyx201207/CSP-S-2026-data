#include<bits/stdc++.h>
using namespace std;
int c1,c2;string s1,s2;string s1a,s2a;char s1b,s2b,s1n,s2n;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<2;i++){
		s1a += s1[i];
		s2a += s2[i];
		
	}
	s1b = s1[2],s2b=s2[2];
	
	if(c1==c2){
		cout<<"1";
		if(s1a==s2a){
			cout<<"1";
			if(s1b=='A'||s1b=='B'||s1b=='C') s1n='l';
			else s1n='r';
			if(s2b=='A'||s2b=='B'||s2b=='C') s2n='l';
			else s2n='r';
			if(s1n==s2n){
				cout<<"1";
				if(s1n=='r'||(s1b-s2b==1||s2b-s1b==1)){
					cout<<"1";
				}
				else cout<<"0";
			} 
			else cout<<"00";
	}
	else cout<<"000";	
	}
	else cout<<"0000";
	//fclose(stdin,stdout);
	return 0;
}
