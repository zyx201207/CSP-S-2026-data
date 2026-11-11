#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
bool v=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) 
	{
		cout<<'1';
		v=1;
	}
	else cout<<'0';
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&v) cout<<'1';
	else 
	{
		cout<<'0';
		v=0;
	}
	if(v) 
	{
		if(s1[2]<='C'&&s1[2]>='A'&&s2[2]<='C'&&s2[2]>='A'||s1[2]>='E'&&s1[2]<='F'&&s2[2]>='E'&&s2[2]<='F') cout<<'1';
		else cout<<'0';
	}
	else 
	{
		cout<<'0';
		v=0;
	}
	if(v)
	{
		int k1=int(s1[2]),k2=int(s2[2]);
		if(k1<k2)
		{
			int x=k1;
			k1=k2;k2=x;
		}
		if(k1-k2==1&&(k1==int('C')||k1==int('F')||k1==int('B'))) cout<<'1';
		else cout<<'0';
	}
	else cout<<'0';
	return 0; 
} 
