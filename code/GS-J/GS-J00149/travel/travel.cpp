#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin); 
	freopen("travel.out","w",stdout);
	char c1[2],s1[2];
	char c2[100],s2[100];
	cin>>c1;
	cin>>c2[0]>>c2[1]>>c2[2];
	cin>>s1;
	cin>>s2[0]>>s2[1]>>s2[2];
	if(c1[0]==s1[0]&&c1[1]==s1[1]){
		cout<<"1";
	}else if(c1[0]!=s1[0]||c1[1]!=s1[1]){
		cout<<"0";
	}	
	if(c1[0]==s1[0]&&c1[1]==s1[1]){
		if(c2[0]==s2[0]&&c2[1]==s2[1]){
			cout<<"1";
		}else if(c2[0]!=s2[0]||c2[1]!=s2[1]){
			cout<<"0";
		}
	}else{
		cout<<"0";
	}
	if(c1[0]==s1[0]&&c1[1]==s1[1]){
		if(c2[0]==s2[0]&&c2[1]==s2[1]){
			if(c2[2]=='A'&&(s2[2]=='B'||s2[2]=='C')){
				cout<<"1";
			}else if(c2[2]=='B'&&(s2[2]=='A'||s2[2]=='C')){
				cout<<"1";
			}else if(c2[2]=='C'&&(s2[2]=='A'||s2[2]=='B')){
				cout<<"1";
			}else if(c2[2]=='D'&&s2[2]=='F'){
				cout<<"1";
			}else if(c2[2]=='F'&&s2[2]=='D'){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}else{
			cout<<"0";
		}
	}else{
		cout<<"0";
	}
	if(c1[0]==s1[0]&&c1[1]==s1[1]){
		if(c2[0]==s2[0]&&c2[1]==s2[1]){
			if(c2[2]=='A'&&s2[2]=='B'){
				cout<<"1";
			}else if(c2[2]=='B'&&(s2[2]=='A'||s2[2]=='C')){
				cout<<"1";
			}else if(c2[2]=='C'&&s2[2]=='B'){
				cout<<"1";	
			}else if(c2[2]=='D'&&s2[2]=='F'){
				cout<<"1";	
			}else if(c2[2]=='F'&&s2[2]=='D'){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}else{
			cout<<"0";
		}
	}else{
		cout<<"0";
	}
			
	
	
	return 0;
}

