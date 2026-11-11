#include<bits/stdc++.h>
using namespace std;
bool e[5];
int main()
{
	string c1,s1,c2,s2;
	bool ss1,ss2;
	cin>>c1>>s1>>c2>>s2;
	if(s1[2]=='C'||s1[2]=='B'||s1[2]=='A')ss1=1;
	if(s2[2]=='C'||s2[2]=='B'||s2[2]=='A')ss2=1;
	if(s1[2]=='D'||s1[2]=='F')ss1=0;
	if(s2[2]=='D'||s2[2]=='F')ss2=0;
	int S1,S2;
	if(s1[2]=='A')S1=1;
	if(s1[2]=='B')S1=2;
	if(s1[2]=='C')S1=3;
	if(s1[2]=='D')S1=5;
	if(s1[2]=='F')S1=6;
	if(s2[2]=='A')S2=1;
	if(s2[2]=='B')S2=2;
	if(s2[2]=='C')S2=3;
	if(s2[2]=='D')S2=5;
	if(s2[2]=='F')S2=6;
	if(c1==c2)
	{
	    e[0]=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
		    e[1]=1;	
			if(ss1==ss2)
			{
				e[2]=1;
				if(S1-S2==1||S2-S1==1)e[3]=1;
			}
			
		}
	}
	for(int i=0;i<=3;i++)
	{
		cout<<e[i];
	}
	return 0;
} 
