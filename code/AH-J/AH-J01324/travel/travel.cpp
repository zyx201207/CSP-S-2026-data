#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,s="0000";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c&&a!="01"&&a!="16"){
		s[0]='1';
	}
	else{
		cout<<s;
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]){
		s[1]='1';
	}
	else{
		cout<<s;
		return 0;
	}
	if(b[2]=='D'&&d[2]=='F'){
		s[2]='1';s[3]='1';
		cout<<s;
	}
	else if(b[2]=='F'&&d[2]=='D'){
		s[2]='1';s[3]='1';
		cout<<s;
	}
	else if(b[2]=='A'&&d[2]=='C'){
		s[2]='1';
		cout<<s;
	}
	else if(b[2]=='A'&&d[2]=='B'){
		s[2]='1';s[3]='1';
		cout<<s;
	}
	else if(b[2]=='B'&&d[2]=='A'){
		s[2]='1';s[3]='1';
		cout<<s;
	}
	else if(b[2]=='B'&&d[2]=='C'){
		s[2]='1';s[3]='1';
		cout<<s;
	}
	else if(b[2]=='C'&&d[2]=='A'){
		s[2]='1';
		cout<<s;
	}
	else if(b[2]=='C'&&d[2]=='B'){
		s[2]='1';s[3]='1';
		cout<<s;
	}
	else{
		cout<<s;
	}
	return 0;
}
