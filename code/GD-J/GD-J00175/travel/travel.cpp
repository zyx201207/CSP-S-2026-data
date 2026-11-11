#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,r1,s2,r2;
	cin>>r1>>s1>>r2>>s2;
	bool f=1;
	if(r1==r2)//µÚÒ» 
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1])//µÚ¶þ 
	{
		cout<<1;
	}
	else
	{
		f=0;
		cout<<0;
	}
	if(f)//µÚÈý 
	{
		if(s1[2]<'D'&&s2[2]<'D'||s1[2]>='D'&&s2[2]>='D')
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	else
	{
		cout<<0;
	}
	if(f)
	{
		if(s1[2]=='D'&&s2[2]=='F'||s2[2]=='D'&&s1[2]=='F')
		{
			cout<<1;
		}
		else if(s1[2]=='B'&&(s2[2]=='C'||s2[2]=='A')||s2[2]=='B'&&(s2[2]=='C'||s1[2]=='A'))
		{
			cout<<1;
		}
		else 
		{
			cout<<0;
		}
	 } 
	 else
	 {
		cout<<0;
	 }
	return 0;
 } 
 //ÍËÒÛ´ó¼ª
//ÍËÒÛ´ó¼ª
//ÍËÒÛ´ó¼ª
//ÍËÒÛ´ó¼ª
//ÍËÒÛ´ó¼ª//ÍËÒÛ´ó¼ª//ÍËÒÛ´ó¼ª
//ÍËÒÛ´ó¼ª
//ÍËÒÛ´ó¼ª//ÍËÒÛ´ó¼ª
 
