#include <bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
//char a[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int f=0;
	if(c1==c2){
	  cout<<1;
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='D'||s2[2]=='F')){
		cout<<0;
	}else if((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&(s1[2]=='D'||s1[2]=='F')){
		cout<<0;
	}else{
		cout<<1;
		f=1;
	}
	if(f==1){
		if(s1[2]=='C'){
			if(s2[2]=='B'){
				cout<<1;
			}else{
				cout<<0;
			}
		}else if(s2[2]=='C'){
			if(s1[2]=='B'){
				cout<<1;
			}else{
				cout<<0;
			}
		}else if(s1[2]=='D'){
			if(s2[2]=='F'){
				cout<<1;
			}else{
				cout<<0;
			}
		}else if(s2[2]=='D'){
			if(s1[2]=='F'){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			if(s1[2]-1==s2[2]){
				cout<<1;
			}else if(s2[2]-1==s1[2]){
				cout<<1;
			}else{
				cout<<0;
			} 
		}
	}else{
		cout<<0;
	}
	/*if(s1[2]=='C'){
		if(s2[2]=='D'){
			cout<<0;
			f=3;
		}
		else{
		  cout<<1;
		  f=1;
		}
	}
	else if(s1[2]=='D'){
		if(s2[2]=='C'){
			cout<<0;
			f=4;
		}
		else{
		  cout<<1;
		  f=2;
		}
	}
	if(f==0||f==1||f==2){
		if(f==0){
			if(s1[2]-'A'-1==s2[2]){
				cout<<1;
			}else if(s2[2]-'A'-1==s1[2]){
				cout<<1;
			}else{
				cout<<0;
			}
		}else if(f==1){
			if(s1[2]-'A'-1==s2[2]){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			if(s2[2]-'A'+1==s1[2]){
				cout<<1;
			}else{
				cout<<0;
			}
		}
	}else if(f==3||f==4){
		cout<<0;
	}else{
		if(s1[2]-'A'-1==s2[2]-'A'){
			cout<<1;
		}else if(s2[2]-'A'-1==s1[2]-'A'){
			cout<<1;
		}
	}*/
	
	
	
	return 0;
} 
