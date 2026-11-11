//GZ-J00159 六盘水市第二十四中学 杨沛雯 
#include<bits/stdc++.h>
using namespace std;
char c1[10],s1[10],c2[10],s2[10];
int main()
{	
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
	for(int i=1;i<=2;i++)
	{
		cin>>c1[i];
	}
	for(int i=1;i<=3;i++)
	{
		cin>>s1[i];
	}
	for(int i=1;i<=2;i++)
	{
		cin>>c2[i];
	}
	for(int i=1;i<=3;i++)
	{
		cin>>s2[i];
	}
     if(c1[1]==c2[1]&&c1[2]==c2[2])
     cout<<1;
     else 
     {
     	cout<<"0000";
     	return 0;
	 }
   if(s1[1]==s2[1]&&s1[2]==s2[2])
     cout<<1;
     else 
     {
     	cout<<"000";
     	return 0;
	 }
	if(s1[3]=='F'&&s2[3]=='D')
	{
	cout<<11;
	return 0;
    }
	else if(s1[3]=='D'&&s2[3]=='F')
	{
	cout<<11;
	return 0;
    }
    else if(s1[3]=='C'&&s2[3]=='D')
	{
	cout<<"00";
	return 0;
    }
    else if(s1[3]=='D'&&s2[3]=='C')
	{
	cout<<"00";
	return 0;
    }
	else if(s1[3]=='A'&&s2[3]=='B')
	{
    cout<<11;
    return 0;
    }
    else if(s1[3]=='B'&&s2[3]=='A')
	{
    cout<<11;
    return 0;
    }
    else if(s1[3]=='B'&&s2[3]=='C')
	{
    cout<<11;
    return 0;
    }
     else if(s1[3]=='C'&&s2[3]=='B')
	{
    cout<<11;
    return 0;
    }
    else if(s1[3]-'1'!=s2[3]&&s1[3]+'1'!=s2[3]) 
	{
	cout<<10;
	return 0;
    }
    else
    cout<<"00";
return 0;
}
