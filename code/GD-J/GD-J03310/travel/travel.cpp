#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}
	else {
		cout<<0<<0<<0<<0;
		return 0;
	}
	bool ok=1;
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i]){
			ok=0;
		}
	}
	if(ok){
		cout<<1;
		if((s1[2]=='A'&&(s2[2]=='B'||s2[2]=='C'))||(s1[2]=='B'&&(s2[2]=='C'||s2[2]=='A'))||(s1[2]=='C'&&(s2[2]=='B'||s2[2]=='A'))||(s1[2]=='F'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='F')){
			cout<<1;	
		}
		else{
			cout<<0<<0;
			return 0;
		}
			
		
		if(s1[2]=='F'&&s2[2]=='D'||(s1[2]=='D'&&s2[2]=='F')){
			cout<<1;
		}
		else if(s1[2]=='C'&&s2[2]=='D'||(s1[2]=='D'&&s2[2]=='C')){
			cout<<0;
		}
		else if(s1[2]==(s2[2]-1)||s1[2]==(s2[2]+1)){
			cout<<1;
		}	
		else cout<<0;
		return 0;		
	}
	else
		cout<<0<<0<<0;
	return 0;
	
} 
