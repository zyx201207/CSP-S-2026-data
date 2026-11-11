#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
string s1,s2,c1,c2,ans="";

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) ans+="1";
	else
	{
		cout<<"0000";
		return 0;
	}
	
	ll num1=10*(ll)(s1[0]-'0')+(ll)(s1[1]-'0');
	ll num2=10*(ll)(s2[0]-'0')+(ll)(s2[1]-'0');
	if(num1==num2) ans+="1";
	else
	{
		cout<<"1000";
		return 0;
	}
	
	char ch1=s1[2],ch2=s2[2];
	if(ch1=='A'&&ch2=='B') ans+="1";
	else if(ch1=='A'&&ch2=='C') ans+="1";
	else if(ch1=='B'&&ch2=='A') ans+="1";
	else if(ch1=='B'&&ch2=='C') ans+="1";
	else if(ch1=='C'&&ch2=='A') ans+="1";
	else if(ch1=='C'&&ch2=='B') ans+="1";
	else if(ch1=='D'&&ch2=='F') ans+="1";
	else if(ch1=='F'&&ch2=='D') ans+="1";
	else
	{
		cout<<"1100";
		return 0;
	}
	
	if(ch1=='A'&&ch2=='B') ans+="1";
	else if(ch1=='B'&&ch2=='A') ans+="1";
	else if(ch1=='B'&&ch2=='C') ans+="1";
	else if(ch1=='C'&&ch2=='B') ans+="1";
	else if(ch1=='D'&&ch2=='F') ans+="1";
	else if(ch1=='F'&&ch2=='D') ans+="1";
	else
	{
		cout<<"1110";
		return 0;
	}
	
	cout<<ans;
	
	return 0;
}
//Trick||Treat!
