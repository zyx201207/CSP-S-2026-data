#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2; 
	string ans="";
	
	if(c1==c2 && c1!="01" && c1!="16"){
		ans+='1';
	}
	else{
		ans+="0000"; 
		cout<<ans;
		return 0;
	}
	
	
	
	
	string c21="",c22="";
	for(int i=0;i<=1;i++){
		c21+=s1[i];
		c22+=s2[i];
	}
	int s21=stoi(c21),s22=stoi(c22);
	
	if(s21==s22){
		ans+='1';
	}
	else{
		ans+="000";
		cout<<ans;
		return 0; 
	}
	
	
	
	
	char u1=s1[2],u2=s2[2];
	
	if((u1=='F'  || u1=='D') && (u2=='C' || u2=='B' || u2=='C')){
		ans+="00";
		cout<<ans;
		return 0;
	}
	else if((u2=='F'  || u2=='D') && (u1=='C' || u1=='B' || u1=='C')){
		ans+="00"; 
		cout<<ans;
		return 0;
	}
	else{
		ans+='1';
	}
	
	
	
	
	if(u1+1==u2 || u1-1==u2){
		ans+='1';
	}
	else{
		ans+='0'; 
	}
	cout<<ans;
	return 0;
} 
