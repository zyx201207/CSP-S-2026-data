#include <bits/stdc++.h>
using namespace std;
int main()
{
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	for(int i=0;i<2;i++)
	{
		if(s1[i]!=s2[i])
		{
			cout<<"000";
			return 0;
		}
	}
	cout<<"1";
	char sa=s1[2],sb=s2[2];
	if(sa=='A'&&(sb=='D'||sb=='F'))
	{
		cout<<"00";
		return 0;
	}
	if(sa=='B'&&(sb=='D'||sb=='F'))
	{
		cout<<"00";
		return 0;
	}
	if(sa=='C'&&(sb=='D'||sb=='F'))
	{
		cout<<"00";
		return 0;
	}
	if(sb=='A'&&(sa=='D'||sa=='F'))
	{
		cout<<"00";
		return 0;
	}
	if(sb=='B'&&(sa=='D'||sa=='F'))
	{
		cout<<"00";
		return 0;
	}
	if(sb=='C'&&(sa=='D'||sa=='F'))
	{
		cout<<"00";
		return 0;
	}
	cout<<"1";
	if(sa=='A'&&sb=='B')
	{
		cout<<"1";
		return 0;
	}
	if(sa=='B'&&(sb=='A'||sb=='C'))
	{
		cout<<"1";
		return 0;
	}
	if(sa=='D'&&sb=='F')
	{
		cout<<"1";
		return 0;
	}
	if(sb=='A'&&sa=='B')
	{
		cout<<"1";
		return 0;
	}
	if(sb=='B'&&(sa=='A'||sa=='C'))
	{
		cout<<"1";
		return 0;
	}
	if(sb=='D'&&sa=='F')
	{
		cout<<"1";
		return 0;
	}
	cout<<"0";
}
