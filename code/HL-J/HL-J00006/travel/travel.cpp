#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);	
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	int a=0,b=0,c=s2[s2.size()-1]-'0',d=s4[s4.size()-1]-'0',x,y=0,z=0;
	for(int i=0;i<s1.size();i++){
		y=y*10+s1[i]-'0';
	}
	for(int i=0;i<s3.size();i++){
		z=z*10+s3[i]-'0';
	}
	if(y!=z){
		cout<<"0000";
		return 0;	
	}
	for(int i=0;i<s2.size()-1;i++){
			a=a*10+(s2[i]-'0');
	}
	for(int i=0;i<s4.size()-1;i++){
			b=b*10+(s4[i]-'0');
	}
	if(a!=b){
		cout<<"1000";
		return 0;
	}
	if(s2[s2.size()-1]>='A'&&s2[s2.size()-1]<='C'&&s4[s4.size()-1]>='A'&&s4[s4.size()-1]<='C'){
		x=0;	
	}else if(s2[s2.size()-1]>='D'&&s2[s2.size()-1]<='F'&&s4[s4.size()-1]>='D'&&s4[s4.size()-1]<='F'){
		 		x=1;
	}else{
		cout<<"1100";
		return 0;
	}
	if(x==1){
		if((c+'0'=='D'&&d+'0'=='F')||(d+'0'=='D'&&c+'0'=='F')){
			cout<<"1111";
			return 0;	
		}	
	}else{
		if(c+1==d||c-1==d){
			cout<<"1111";	
			return 0;	
		}else{
			cout<<"1110";
			return 0;
		}		
	}
	return 0;
}

