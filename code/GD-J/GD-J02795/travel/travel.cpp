#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int s,c;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3) cout<<1;
	else
	{
		cout<<"0000";
		return 0;
	}
	int f=1;
	for(int i=0;i<=1;i++)
	{
		if(s2[i]!=s4[i]) f=0;
	}
	if(f==1) cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
	int k=1;
	if(s2[2]=='F'&&s4[2]=='D') cout<<1;
	else if(s2[2]!='F'&&s4[2]!='D') cout<<1;
	else
	{
		cout<<"00";
		return 0;
	}
	if(s2[2]-s4[2]==1||s4[2]-s2[2]==1) cout<<1;
	else cout<<0;
	return 0;
} 
