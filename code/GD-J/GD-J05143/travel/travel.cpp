#include<bits/stdc++.h>
using namespace std; 
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1)
	{
		cout<<"1";
	}else
	{
		cout<<"0000";
		return 0;
	}
	if(c2[0]==s2[0]&&c2[1]==s2[1])
	{
		cout<<"1";
	}else
	{
		cout<<"000";
		return 0;
	}
	char a=c2[2];
	char b=s2[2];
	int aa=(int)a;
	int bb=(int)b;
	if(a>='A'&&a<='C')
	{
		if(b>='A'&&b<='C')
		{
			cout<<"1";
			if(max(aa,bb)-min(aa,bb)==1)
			{
				cout<<"1";
			}else
			{
				cout<<"0";
			}
		}else
		{
			cout<<"00";
			return 0;
		}
	}else
	{
		if(b>='D'&&b<='E')
		{
			cout<<"11";
		}else
		{
			cout<<"00";
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
