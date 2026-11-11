#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r","stdin");
	freopen("travel.out","w","stdout");
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	//q1
	int q=0;
	if(c1==c2) {
		q=1;
		cout<<1;
	}
	else cout<<0; 
	//q2
	if(q=1){
	q=0;
	string sn1,sn2;
	sn1=s1[0]+s1[1];
	sn2=s2[0]+s2[1];
	
		
		if(sn1==sn2) {
			q=1;
			cout<<1;
		}
		else cout<<0;
	}
	else cout<<0;
	//q3
	if(q=1){
		q=0;
		s1[2]=s1[2];
		s2[2]=s2[2];
		if(((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C'))||((s1[2]>='D'&&s1[2]<='F')&&(s2[2]>='D'&&s2[2]<='F'))){
			q=1;
			cout<<1;
		} 
		else cout<<0;
	}
	else cout<<0;
	//q4
	if(q=1){
	
		q=0;
		if((s1[2]=='C'||s1[2]=='D')&&(s2[2]=='C'||s2[2]=='D'))cout<<0;	
		else {
			if((abs(s1[2]-s2[2])==1)||((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))) cout<<1;
			else cout<<0;
		}
		
		
	}
	else cout<<0;
	
	return 0;
}
