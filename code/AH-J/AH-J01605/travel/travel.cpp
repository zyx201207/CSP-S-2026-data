#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
bool f1,f2,f3;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>c1>>c2;
	if(s1!=c1) cout<<0;
	else cout<<1,f1=1;
	string k1=s2.substr(0,2);
	string k2=c2.substr(0,2);
	if(k1==k2&&f1) cout<<1,f2=1;
	else cout<<0;
	if(((s2[2]=='A'&&(c2[2]=='B'||c2[2]=='C'))||(s2[2]=='B'&&(c2[2]=='A'||c2[2]=='C'))||(s2[2]=='C'&&(c2[2]=='A'||c2[2]=='B'))||(s2[2]=='D'&&c2[2]=='F')||(s2[2]=='F'&&c2[2]=='D'))&&f2) cout<<1,f3=1;
	else cout<<0;
	if(((s2[2]=='A'&&c2[2]=='B')||(s2[2]=='B'&&c2[2]=='A')||(s2[2]=='B'&&c2[2]=='C')||(s2[2]=='C'&&c2[2]=='B')||(s2[2]=='D'&&c2[2]=='F')||(s2[2]=='F'&&c2[2]=='D'))&&f3) cout<<1;
	else cout<<0;
	return 0;
} 
