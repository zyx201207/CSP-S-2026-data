#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string a,b,c,d;
string ans="0000";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1)
	{
		ans="1000";
	if(c2[0,0]==s2[0,0]||c2[0,1]==s2[0,1])
	{
	ans="1100";
	if(c2[2]=='A'||s2[2]=='B'){
		ans="1110";
	if(c2[2]=='B'||s2[2]=='A')ans="1110";
	if(c2[2]=='C'||s2[2]=='A')ans="1110";
	if(c2[2]=='A'||s2[2]=='C')ans="1110";
	if(c2[2]=='B'||s2[2]=='C')ans="1110";
	if(c2[2]=='C'||s2[2]=='B')ans="1110";
	if(c2[2]=='D'||s2[2]=='F')ans="1110";
	if(c2[2]=='F'||s2[2]=='D')ans="1110";
	
	if(c2[2]=='A'||s2[2]=='B')
	{
	ans="1111";
	if(c2[2]=='B'||s2[2]=='A')ans="1111";
	if(c2[2]=='B'||s2[2]=='C')ans="1111";
	if(c2[2]=='C'||s2[2]=='B')ans="1111";
	if(c2[2]=='D'||s2[2]=='F')ans="1111";
	if(c2[2]=='F'||s2[2]=='D')ans="1111";
	}else ans="1110";
	}else ans="1100";
	}else ans="1000";
	}else ans="0000";
	cout<<ans;
	return 0;
}
