#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int s=0;
int q=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	
	if(s1==s2){
		cout<<"0000";
		return 0;
	}
	if(s1[0]>='2'||s2[0]>='2'){
		cout<<"0000";
		return 0;
	}
	if(s1[0]=='1'&&s1[1]=='9'||s1[0]=='1'&&s1[1]=='9'){
		cout<<"0000";
		return 0;
	}
	if(s1[0]=='0'&&s1[2]=='1'||s1[0]=='1'&&s1[2]=='7'){
		cout<<"0000";
		return 0;
	}
	if(s1[0]=='0'&&s1[2]=='1'||s1[0]=='1'&&s1[2]=='7'){
		cout<<"0000";
		return 0;
	}
	
	
	
	if(s1[2]>='A'&&s1[2]<='F'&&s2[2]>='A'&&s2[2]<='F'&&s1[2]!='E'&&s2[2]!='E'){
		
	}
	else{
		cout<<"0000";
		return 0;
	}
	
	
	if(c1==c2)cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<"1";
	}else{
		cout<<"0";
	}
	
	if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'&&s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<"1";
		s=1;
	}
	else if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'&&s1[2]!='E'&&s2[2]!='E'&&s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<"1";
		s=1;
		q=1;
	}
	else{
		cout<<"0";
	}
	
	if(s==0){
		cout<<"0"; 
		return 0;
	}
	else if(s==1&&q==1){
		cout<<1;
		return 0;
	}
	else if(s==1){
		int h=abs(s1[2]-s2[2]);
		if(h==1){
			cout<<"1";
			return 0;
		}
		else{
			cout<<"0";
			return 0;
		}
	}
	return 0;
} 
