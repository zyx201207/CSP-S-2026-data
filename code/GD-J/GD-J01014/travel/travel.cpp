#include<bits/stdc++.h>
using namespace std;
string s,ss,sss,ssss;
bool ok;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s>>ss>>sss>>ssss;
	if(s==sss)cout<<1;
	else {cout<<"0000";return 0;}
	for(int i=0;i<=1;i++)
	{
		if(ss[i]!=ssss[i]){cout<<"000";return 0;}
	}
	cout<<1;
	if(ss[2]=='E'&&ssss[2]=='D'||ss[2]=='D'&&ssss[2]=='E'){cout<<"11";return 0;}
	else if(ss[2]=='A'&&ssss[2]=='B'||ss[2]=='A'&&ssss[2]=='C'||ss[2]=='C'&&ssss[2]=='B'||ss[2]=='C'&&ssss[2]=='A'||ss[2]=='B'&&ssss[2]=='A'||ss[2]=='B'&&ssss[2]=='C')
	cout<<1;
	else {cout<<"00";return 0;} 
	if(ss[2]=='C'&&ssss[2]=='B'||ss[2]=='B'&&ssss[2]=='C'||ss[2]=='B'&&ssss[2]=='A'||ss[2]=='A'&&ssss[2]=='B')
	{cout<<"1";return 0;}
	else {cout<<"0";return 0;}
	return 0;
	
} 
