#include <bits/stdc++.h>
using namespace std;
	int p;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	char s1[3],s2[3];
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}

	if(c1==c2&&s1[1]==s2[1]){
		cout<<1;
		
	}else{
		cout<<0;
		p=0;
	}

	if(c1==c2&&s1[1]==s2[1]){
		if(s2[2]=='C'&&s1[2]=='B'){
			cout<<1;
			p=1;
		}else if(s2[2]=='C'&&s1[2]=='B'){
			cout<<1;
			p=1;
		}else if(s2[2]=='C'&&s1[2]=='A'){
			cout<<1;
			p=1;
		}else if(s2[2]=='B'&&s1[2]=='A'){
			cout<<1;
			p=1;
		}else if(s2[2]=='B'&&s1[2]=='C'){
			cout<<1;
			p=1;
		}else if(s2[2]=='A'&&s1[2]=='C'){
			cout<<1;
			p=1;
		}else if(s2[2]=='A'&&s1[2]=='B'){
			cout<<1;
			p=1;
		}else if(s2[2]=='D'&&s1[2]=='F'){
			cout<<1;
			p=1;
		}else if(s2[2]=='F'&&s1[2]=='D'){
			cout<<1;
			p=1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	if(p==1){
	if(s1[2]-s2[2]==1||s2[2]-s1[2]==1||s2[2]==s1[2]+1||s1[2]==s2[2]+1){
		cout<<1;
	}else{
		cout<<0;
	}	
	}else{
		cout<<0;
	}
	
}
