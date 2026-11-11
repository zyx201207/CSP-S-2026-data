#include<bits/stdc++.h>
using namespace std;
string s1,c1,s2,c2;
string ss1,ss2;
string z;
bool flag1 = false,flag2 = false,flag3 = false;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	int a=s1.size(),b=s2.size();
	for(int i = 0;i<s1.size()-1;i++)
	{
		ss1+=s1[i]; 
	}
	for(int i = 0;i<s1.size()-1;i++)
	{
		ss2+=s2[i]; 
	}
	if(c1 == c2)
	{
		z+='1';
		flag1 = true;
	}
	else
	{
		z+='0';
	}
	if(ss1 == ss2 and flag1)
	{
		z+='1';
		flag2 = true;
	}
	
	else
	{
		z+='0';	
	}
	if((s1[a-1]>='A' and s1[a-1]<='C' and s2[b-1]>='A' and s2[b-1]<='C' or 
	s1[a-1]>='D' and s1[a-1]<='F' and s2[b-1]>='D' and s2[b-1]<='F') and flag1 and flag2)
	{
		flag3 = true;
		z+='1';
	}
	else
	{
		z+='0';
	}
	if((s1[a-1]+1 == s2[b-1] or s1[a-1] == s2[b-1]+1) and flag1 and flag2 and flag3)
	{
		z+='1';
	}
	else
	{
		z+='0'; 
	}
	cout<<z;
	return 0;
} 
