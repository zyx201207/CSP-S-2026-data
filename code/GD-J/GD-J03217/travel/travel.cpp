#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("travel""r"stdin);
	//freopen("travel""w"stdout);
	int pai[10];
	char  c1[2],s1[3],c2[2],s2[3];
	cin>>c1[0]>>c1[1]>>s1[0]>>s1[1]>>s1[2]>>c2[0]>>c2[1]>>s2[0]>>s2[1]>>s2[2];
	if(c1[0]==c2[0]&&c1[1]==c2[1]) cout<<1;
	else{cout<<"0000";return 0;}
	if(s1[0]==s2[0]&&s1[1]==s2[1]) cout<<1;
	else{cout<<"000";return 0;}
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C') pai[1]=0;
	else pai[1]=1;
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C') pai[2]=0;
	else pai[2]=1;
	if(pai[1]==pai[2]) cout<<1;
	else{cout<<"00";return 0;}
	if(s1[2]=='A'&&s2[2]=='B') cout<<1;
	else if(s1[2]=='B'&&s2[2]=='C') cout<<1;
	else if(s1[2]=='B'&&s2[2]=='A') cout<<1;
	else if(s1[2]=='C'&&s2[2]=='B') cout<<1;
	else if(s1[2]=='D'&&s2[2]=='E') cout<<1;
	else if(s1[2]=='E'&&s2[2]=='D') cout<<1;
	else cout<<0;
	return 0;
	
}
