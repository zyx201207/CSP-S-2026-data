#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int mark=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1!=s3)
	{
		cout<<0;
		mark=1;
	}
	else
	{
		cout<<1;
	}
	if(s2[0]==s4[0]&&s2[1]==s4[1]&&(!mark))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
		mark=1;
	}
	if((s2[2]>='D'&&s4[2]>='D'&&(!mark))||(s2[2]<='C'&&s4[2]<='C'&&(!mark)))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
		mark=1;
	}
	if(mark)
	{
		cout<<0;
	}
	else  if((s2[2]=='D'&&s4[2]=='F')||(s2[2]=='F'&&s4[2]=='D'))
	{
		cout<<1;
	}
	else  if(abs(int(s2[2])-int(s4[2]))==1)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
