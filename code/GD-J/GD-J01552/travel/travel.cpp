#include<bits/stdc++.h>
using namespace std;
string a,b,a1,b1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>a1>>b1;
	if(a==a1)cout<<'1';
	else cout<<'0';
	string s=b.substr(0,2),s1=b1.substr(0,2);
	if(s==s1)cout<<'1';
	else cout<<'0';
	if(((b[2]=='D'&&b1[2]=='F')||(b[2]=='F'&&b1[2]=='D'))
	||((b[2]=='A'&&b1[2]=='C')||(b[2]=='C'&&b1[2]=='A')||(b[2]=='A'&&b1[2]=='B')
	||(b[2]=='B'&&b1[2]=='A')||(b[2]=='B'&&b1[2]=='C')||(b[2]=='C'&&b1[2]=='B')))cout<<'1';
	else cout<<'0'; 
	if(b1[2]=='F')b1[2]='E';
	if(abs((int)b[2]-(int)b1[2])==1)cout<<'1';
	else cout<<'0'; 
}
