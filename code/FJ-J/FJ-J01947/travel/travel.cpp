#include<bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	if(c==cc) cout<<'1';
	else{
		cout<<'0'<<'0'<<'0'<<'0';
		return 0;
	} 
	if(s[0]==ss[0]&&s[1]==ss[1])  cout<<'1';	
	else{
		cout<<'0'<<'0'<<'0';
		return 0;
	} 
	int a,b;
	if(s[2]=='A') a=1;
	if(s[2]=='B') a=2;
	if(s[2]=='C') a=3;
	if(s[2]=='D') a=4;
	if(s[2]=='F') a=5;
	if(ss[2]=='A') b=1;
	if(ss[2]=='B') b=2;
	if(ss[2]=='C') b=3;
	if(ss[2]=='D') b=4;
	if(ss[2]=='F') b=5;
	if(a>=1&&a<=3&&b>=1&&b<=3) cout<<'1';
	else if(a>=4&&a<=5&&b>=4&&b<=5) cout<<'1'; 
	else {
		cout<<'0'<<'0';
		return 0;
	}
	if(abs(a-b)==1) cout<<'1';
	else cout<<'0';
	return 0;
} 
