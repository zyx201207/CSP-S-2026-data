#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	bool a=0,b=0,c=0;
	cin>>c1>>s1>>c2>>s2; 
	if(c1==c2){
		cout<<1;
		a=1;
	}
	else{
		cout<<0;
	} 
	if(s1[0]*10+s1[1]==s2[0]*10+s2[1]){
		if(a==1){
		cout<<1;
		b=1;	
		}
		else{
		cout<<0; 
		} 
	}
	else{
	    cout<<0;	
	}
	if(s1[2]=='F'&&s2[2]=='D'||s1[2]=='D'&&s2[2]=='F'&&b==1){
		if(b==1){
		cout<<1;
		c=1;	
		}
		else{
		cout<<0; 
		} 
	}
	else if(s1[2]=='A'&&s2[2]=='B'||s2[2]=='C'||s1[2]=='B'&&s2[2]=='A'||s2[2]=='C'||s1[2]=='C'&&s2[2]=='A'||s2[2]=='B'&&b==1){
		if(b==1){
		cout<<1;
		c=1;	
		}
		else{
		cout<<0; 
		} 
	}
	else{
		cout<<0;
	}
	if(s1[2]=='F'&&s2[2]=='D'||s1[2]=='D'&&s2[2]=='F'&&c==1){
		if(c==1){
		cout<<1;	
		}
		else{
		cout<<0; 
		} 
	}
	else if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='A'||s2[2]=='C'||s1[2]=='C'&&s2[2]=='B'){
		if(c==1){
		cout<<1;	
		}
		else{
		cout<<0; 
		} 
	}
	else{
		cout<<0;
	}	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
