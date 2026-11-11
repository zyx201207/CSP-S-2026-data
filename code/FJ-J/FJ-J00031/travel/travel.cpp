#include<map>
#include<queue>
#include<vector>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
string s1,s2,s3,s4;
int toint(string s)
{
	return s[0]*10+s[1];
}
inline long long read()
{
	long long f=1,x=0;
	char c;
	c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-')
			f*=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}
int main()
{
	freopen("travel.in","r",stdin); 
	freopen("travel.out","w",stdout); 
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3)//同一节车厢 
	{
		cout<<"1";
		if(s2[0]==s4[0]&&s2[1]==s4[1])//同一排 
		{
			cout<<"1";
			if(((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&(s4[2]=='A'||s4[2]=='B'||s4[2]=='C'))||((s2[2]=='D'||s2[2]=='F')&&(s4[2]=='D'||s4[2]=='F')))//同一侧 
			{
				cout<<"1";
				if((abs(toint(s2)-toint(s4))+abs(s2[2]-s4[2]))==1)
					cout<<"1";
				else
					cout<<"0";
			}
			else
				cout<<"00";
		}
		else
			cout<<"000";
	}
	else
		cout<<"0000";
} 
