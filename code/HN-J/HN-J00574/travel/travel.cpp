#include<bits/stdc++.h>
using namespace std;	
int cx,cx2;
string s,s2; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cx>>s;
	cin>>cx2>>s2;
	if(cx==cx2) cout<<1;
	else cout<<0;
	if(cx==cx2&&s[0]==s2[0]&&s[1]==s2[1]) cout<<1;
	else cout<<0;
	if(cx==cx2&&s[0]==s2[0]&&s[1]==s2[1]){
		if(s[2]=='A'&&s2[2]!='D'||s[2]=='A'&&s2[2]!='F') cout<<1;
		else if(s[2]=='B'&&s2[2]!='D'||s[2]=='B'&&s2[2]!='F') cout<<1;
		else if(s[2]=='C'&&s2[2]!='D'||s[2]=='C'&&s2[2]!='F') cout<<1;
		else if(s2[2]=='A'&&s[2]!='D'||s2[2]=='A'&&s[2]!='F') cout<<1;
		else if(s2[2]=='B'&&s[2]!='D'||s2[2]=='B'&&s[2]!='F') cout<<1;
		else if(s2[2]=='C'&&s[2]!='D'||s2[2]=='C'&&s[2]!='F') cout<<1;
		else cout<<0;
	}
	else cout<<0;
	int x=s[0]-'0',y=s[1]-'0';
	int x2=s2[0]-'0',y2=s2[1]-'0';
	int n=max(x*10+y,x2*10+y2);
	int m=min(x*10+y,x2*10+y2);
	if(cx==cx2){
		if(n-m==1&&s[2]==s2[2]||n==m){
			if(s[2]=='A'&&s2[2]!='D'||s[2]=='A'&&s2[2]!='F') cout<<1;
			else if(s[2]=='B'&&s2[2]!='D'||s[2]=='B'&&s2[2]!='F') cout<<1;
			else if(s[2]=='C'&&s2[2]!='D'||s[2]=='C'&&s2[2]!='F') cout<<1;
			else if(s2[2]=='A'&&s[2]!='D'||s2[2]=='A'&&s[2]!='F') cout<<1;
			else if(s2[2]=='B'&&s[2]!='D'||s2[2]=='B'&&s[2]!='F') cout<<1;
			else if(s2[2]=='C'&&s[2]!='D'||s2[2]=='C'&&s[2]!='F') cout<<1;
			else cout<<0;
		}
		else cout<<0;
	}
	else cout<<0;
	return 0;
} 
