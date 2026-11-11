#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool f=false,s=false,t=false,e=false;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		f=true;
	}
	if(f&&s1[0]==s2[0]&&s1[1]==s2[1]){
		s=true;
	}
	if(s){
		if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
			t=true;
		}else{
			if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')){
				t=true;
			}
		}
	}
	if(t){
		if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='F'&&s2[2]=='D')){
			e=true;
		}
	}
	if(f){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(s){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(t){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(e){
		cout<<"1";
	}else{
		cout<<"0";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
