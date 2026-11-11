#include<bits/stdc++.h>
using namespace std;
int c1=0,c2=0;
string s1,s2;
int pan[4]={0,0,0,0};
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	if(c1==c2)
	{
		pan[0]=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			pan[1]=1;
			if((s1[2]>'C'&&s2[2]>'C')||(s1[2]<'D'&&s2[2]<'D'))
			{
				pan[2]=1;
				if(s1[2]>'C'&&s2[2]>'C'&&abs(s1[2]-s2[2])==2)pan[3]=1;
				else if(s1[2]<'D'&&s2[2]<'D'&&abs(s1[2]-s2[2])==1)pan[3]=1;
			}
		}
	}
	cout<<pan[0]<<pan[1]<<pan[2]<<pan[3];
	return 0;
}
