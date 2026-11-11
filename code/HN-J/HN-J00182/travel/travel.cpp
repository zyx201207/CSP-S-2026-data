#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	int a=0,b=0;
	char c;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') a=a*10+(s[i]-'0');
	}cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') b=b*10+(s[i]-'0');
		else c=s[i];
	}cin>>s;
	int x=0,y=0;
	char d;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') x=x*10+(s[i]-'0');
	}cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') y=y*10+(s[i]-'0');
		else d=s[i];
	}
	if(a==x) cout<<1;
	else cout<<0;
	if(b==y) cout<<1;
	else cout<<0;
	if(c>='A'&&c<='C'&&d>='A'&&d<='C'||c>='D'&&c<='F'&&d>='D'&&d<='F'){
		cout<<1;
		if(abs(int(c)-int(d))==1) cout<<1;
		else cout<<0;
	}
	else cout<<"00";
	return 0;
} 
