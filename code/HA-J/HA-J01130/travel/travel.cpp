#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4,s5="",s6="";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		cout<<1; 
	}
	else{
		cout<<0;
	}
	for(int i=0;i<2;i++){
	 	s5+=s2[i];
	}
	for(int i=0;i<2;i++){
	 	s6+=s4[i];
	}
	if(s5==s6&&s1==s3){
		cout<<"1"; 
	}
	else{
		cout<<0;
	}
	char sty=s2[2],sty1=s4[2];
	if((((sty=='A'&&sty1=='B')||(sty=='A'&&sty1=='C')||(sty=='B'&&sty1=='C'))||((sty1=='A'&&sty=='B')||(sty1=='A'&&sty=='C')||(sty1=='B'&&sty=='C')))||((sty=='F'&&sty1=='D')||(sty1=='F'&&sty=='D'))){
		cout<<1;
	}
	else{
		cout<<0; 
	}
	if(((sty=='F'&&sty1=='D')||(sty1=='F'&&sty=='D'))||((sty=='A'&&sty1=='B')||(sty=='B'&&sty1=='C'))||((sty1=='A'&&sty=='B')||(sty1=='B'&&sty=='C'))){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
