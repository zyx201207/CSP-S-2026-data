#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	int c1=(s1[0]-'0')*10+(s1[1]-'0');
	int c2=(s3[0]-'0')*10+(s3[1]-'0');
	if(c1==c2&&c1!=1&&c1!=16&&c2!=1&&c2!=16){
		cout<<1;
	}
	else {cout<<0<<0<<0<<0;
	return 0;
	}
	int p1=(s2[0]-'0')*10+(s2[1]-'0');
	int p2=(s4[0]-'0')*10+(s4[1]-'0');
	if(p1==p2){
		cout<<1;
	}
	else{
		cout<<0<<0<<0;
		return 0;
	} 
	if((s2[2]>='A'&&s2[2]<='C'&&s4[2]>='A'&&s4[2]<='C')||(s2[2]>='D'&&s2[2]<='F'&&s4[2]>='D'&&s4[2]<='F'&&s2[2]!='E'&&s4[2]!='E')){
		cout<<1;
	}else {
		cout<<0<<0;
		return 0;
	}
	int pp=int(s2[2]),pp1=int(s4[2]);
	if(abs(pp-pp1)==1){
		if(s2[2]>='A'&&s2[2]<='F'&&s4[2]>='A'&&s4[2]<='F'&&s2[2]!='E'&&s4[2]!='E'){
		
			if(s2[2]=='C'&&s4[2]=='D'){
				cout<<0;
			}
			else if(s2[2]=='D'&&s4[2]=='C'){
				cout<<0;
			}
			else{
				cout<<1;
			}
		}
		else{
			cout<<0;
		}
	}
	else{
		cout<<0;
	}
	return 0;
} 
