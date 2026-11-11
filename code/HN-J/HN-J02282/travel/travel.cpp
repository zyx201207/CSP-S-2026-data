#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,s1i,s2i,sz1,sz2;
	string s1,s2;
	cin>>a>>s1>>b>>s2;
	if(s1[2]=='A'){
		s1i=1;
	}
	else if(s1[2]=='B'){
		s1i=2;
	}
	else if(s1[2]=='C'){
		s1i=3;
	}
	else if(s1[2]=='D'){
		s1i=4;
	}
	else{
		s1i=5;
	}
	//////////////////
	if(s2[2]=='A'){
		s2i=1;
	}
	else if(s2[2]=='B'){
		s2i=2;
	}
	else if(s2[2]=='C'){
		s2i=3;
	}
	else if(s2[2]=='D'){
		s2i=4;
	}
	else{
		s2i=5;
	}
	/////////////
	if(a!=b){
		cout<<"0000";
	}
	else if((s1[0]!=s2[0])||(s1[1]!=s2[1])){
		cout<<"1000";
	}
			
	else if((s1i<4&&s2i>3)||(s1i>3&&s2i<4)){
		cout<<"1100";
	}
	else if(s1i+1!=s2i&&s1i-1!=s2i){
		cout<<"1110";
	}
	else{
		cout<<"1111";
	}
	cout<<s1i<<' '<<s2i;
	return 0;
}
