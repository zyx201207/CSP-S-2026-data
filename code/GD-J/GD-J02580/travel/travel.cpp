#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1>>s1>>c2>>s2;
	bool t = true;
	for(int i=0;i<2;i++)
	{
		if(c1[i]!=c2[i])
		{
			t = false;
		}
	}
	if(t==true)
	{
		cout << 1;
	}else
	{
		cout << "0000";
		return 0;	
	}
	bool tt = true;
	for(int i=0;i<2;i++)
	{
		if(s1[i]!=s2[i])
		{
			tt = false;
		}
	}
	if(tt = true)
	{
		cout << 1;
	}else
	{
		cout << "000";
		return 0; 
	}
	if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C'))
	{
		cout << 1;
	}else
	{
		cout << "00";
		return 0;
	}
	if((s1[2]+1==s2[2])||s2[2]+1==s1[2])
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	return 0;
	
}
