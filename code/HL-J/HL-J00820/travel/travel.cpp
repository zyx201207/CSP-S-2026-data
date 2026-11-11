#include<bits/stdc++.h>
using namespace std;
int k1,k2,k3,k4;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,s,n;
	cin>>a>>s>>b>>n;
	if(a==b)
	{
		k1=1;
		if(s[0]==n[0]&&s[1]==n[1])
		{
			k2=1;
			//if(s[2]=='D'&&n[2]=='F') k3=1;
			//else if(s[2]=='F'&&n[2]=='D') k3=1;
			if(s[2]=='D'&&n[2]=='F'||s[2]=='F'&&n[2]=='D'||s[2]=='C'&&n[2]=='A'||s[2]=='C'&&n[2]=='B'||s[2]=='A'&&n[2]=='B'||s[2]=='A'&&n[2]=='C'||s[2]=='B'&&n[2]=='C'||s[2]=='B'&&n[2]=='A')
			{
				k3=1;
			}
	}
	}
	if(k1==1&&k2==1&&k3==1)
	{
		if(s[2]-n[2]==1||n[2]-s[2]==1) k4=1;
	}
	cout<<k1<<k2<<k3<<k4;
	return 0;
}