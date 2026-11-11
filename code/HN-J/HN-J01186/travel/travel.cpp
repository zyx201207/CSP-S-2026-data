#include<bits/stdc++.h>
using  namespace  std;
int main()
{
   freopen("travel.in","r",stdin);
   freopen("travel.out","w",stdout);
   string c1,c2,s1,s2;
   cin>>c1>>s1>>c2>>s2;
   if(c1==c2)
   {cout<<"1";} 
   else
   {cout<<"0000";return 0;}
  for(int i=1;i<=19;i++)
  {
  	if(s1[0]==s2[0]&&s1[1]==s2[1])
  	{cout<<"1";break;}
	  else
	{cout<<"000";return 0;}
  }
   for(int i=1;i<=5;i++)
	{
		if(s1[2]=='A'&&s2[2]=='B')
		{cout<<"1";break;}
		if(s1[2]=='A'&&s2[2]=='C')
		{cout<<"1";break;}
		if(s1[2]=='B'&&s2[2]=='C')
		{cout<<"1";break;}
	    if(s1[2]=='D'&&s2[2]=='F')
		{cout<<"1";break;}
		if(s1[2]=='B'&&s2[2]=='A')
		{cout<<"1";break;}
		if(s1[2]=='C'&&s2[2]=='A')
		{cout<<"1";break;}
		if(s1[2]=='C'&&s2[2]=='B')
		{cout<<"1";break;}
	    if(s1[2]=='F'&&s2[2]=='D')
		{cout<<"1";break;}
		else
		{cout<<"0";break;}
	} 
	for(int i=1;i<=11;i++)
	{
		if(s1[2]=='A'&&s2[2]=='B')
		{cout<<"1";break;}
		else if(s1[2]=='B'&&s2[2]=='C')
		{cout<<"1";break;}
		else if(s1[2]=='D'&&s2[2]=='F')
		{cout<<"1";break;}
		else
		{
			cout<<"0";break;
		}
	 } 
	return 0;
}

