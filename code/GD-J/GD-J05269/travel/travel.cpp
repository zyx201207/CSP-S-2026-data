#include<bits/stdc++.h>
using namespace std;
string c1,c2;
char s1[7],s2[7];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1;
	for(int i=1;i<=3;i++){
		cin>>s1[i];
	}
	cin>>c2;
	for(int i=1;i<=3;i++){
		cin>>s2[i];
	}
	if(c1==c2){
		cout<<1;	
		if(s1[1]==s2[1]&&s1[2]==s2[2]){
			cout<<1;
		if(s1[3]=='A'&&s2[3]=='B'){
		cout<<1;
	}
	else if(s1[3]=='B'&&s2[3]=='A'){
		cout<<1;
	}	
	else if(s1[3]=='C'&&s2[3]=='A'){
		cout<<1;
	}
	else if(s1[3]=='B'&&s2[3]=='C'){
		cout<<1;
	}
	else if(s1[3]=='C'&&s2[3]=='B'){
		cout<<1;
	}
	else if(s1[3]=='A'&&s2[3]=='C'){
		cout<<1;
	}	
	else if(s1[3]=='D'&&s2[3]=='E'){
		cout<<1;
	}
	else if(s1[3]=='E'&&s2[3]=='D'){
		cout<<1;
	}	
	else{
		cout<<0<<0;
		return 0;
	}	
	if(s1[3]=='A'){
		if(s2[3]=='B'){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else if(s1[3]=='B'){
		if(s2[3]=='A'){
			cout<<1<<1;
		}
		else if(s2[3]=='C'){
			cout<<1;
		}
		else{
			cout<<0<<0;
			return 0;
		}
	}
	else if(s1[3]=='C'){
		if(s2[3]=='B'){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else if(s1[3]=='D'){
		if(s2[3]=='E'){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else if(s1[3]=='E'){
		if(s2[3]=='D'){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}		
	}
	else{
		cout<<0<<0<<0;
		}
	}
	else{
		cout<<0<<0<<0<<0<<endl;
		return 0;
	}
	return 0;		
} 
