#include <bits/stdc++.h>
using namespace std;
string c[2],s[2];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c[0]>>s[0]>>c[1]>>s[1];
	if(c[0]==c[1]){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(c[0]==c[1]&&s[0][0]==s[1][0]&&s[0][1]==s[1][1]){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(c[0]==c[1]&&s[0][0]==s[1][0]&&s[0][1]==s[1][1]&&(s[0][2]<='C'&&s[1][2]<='C'||s[0][2]>='D'&&s[1][2]>='D')){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(c[0]==c[1]&&s[0][0]==s[1][0]&&s[0][1]==s[1][1]){
		if(s[0][2]=='A'&&s[1][2]=='B')
		cout<<"1";
		else if(s[0][2]=='B'&&(s[1][2]=='A'||s[1][2]=='C'))
		cout<<"1";
		else if(s[0][2]=='C'&&s[1][2]=='B')
		cout<<"1";
		else if(s[0][2]=='D'&&s[1][2]=='F')
		cout<<"1";
		else if(s[0][2]=='F'&&s[1][2]=='D')
		cout<<"1";
		else
		cout<<"0";
	}
	else
	cout<<"0";
	return 0;
}
