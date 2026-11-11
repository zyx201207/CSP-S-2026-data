#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1,b1;
	string a2,b2;
	cin>>a1>>a2>>b1>>b2;

	if(a1==b1){
		cout<<1;
		
	}else{
		cout<<0;
		
	}

	string s1, s2;
	s1+=a2[0];s1+=a2[1];
	s2+=b2[0];s2+=b2[1];
	
	char a=a2[2],b=b2[2];
	if(s1==s2){
		cout<<1;
	}else{
		cout<<0;
		
	}
	if(a<='C'&&b<='C'||a>='D'&&b>='D'){
		cout<<1;
	}
	else{
		cout<<0;
	
	}
	if(a=='A'){
		if(b=='B'){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	else if(a=='B'){
			if(b=='C'||b=='A'){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	else if(a=='C'){
			if(b=='B'){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	else if(a=='D'){
		if(b=='F'){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	else{
		if(b=='D'){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	return 0;
} 
