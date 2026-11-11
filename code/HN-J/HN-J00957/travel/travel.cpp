#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	string a,b;
	cin>>c1>>s1>>c2>>s2; 
	if(c1==c2){
	cout<<1;
	}else {
	cout<<0000;
	}
	if(s1[1]==s2[1]){
	cout<<1; 
	}else {
	cout<<000;
	}
	if(s1[2]=='A'){
		if(s2[2]=='B'){
			cout<<11;
		}
	}if(s1[2]=='B'){
		if(s2[2]=='C'){
			cout<<11;
		}
	}if(s1[2]=='A'){
		if(s2[2]=='C'){
			cout<<10;
		}
	}if(s1[2]=='D'){
		if(s2[2]=='F'){
			cout<<11;
		}
	}
	if(s2[2]=='A'){
		if(s1[2]=='B'){
			cout<<11;
		}
	}if(s2[2]=='B'){
		if(s1[2]=='C'){
			cout<<11;
		}
	}if(s2[2]=='A'){
		if(s1[2]=='C'){
			cout<<10;
		}
	}if(s2[2]=='D'){
		if(s1[2]=='F'){
			cout<<11;
		}
	}
	return 0;
} 
