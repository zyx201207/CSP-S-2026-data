#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
		string str1,str2;
		for(int i=0;i<2;i++)
		{
			str1+=s1[i];
			str2+=s2[i];
		}
		if(str1==str2)
		{
			cout<<1;
			char cha1=s1[2],cha2=s2[2];
			if((cha1<='C'&&cha2<='C')||(cha1>='D'&&cha2>='D'))
			{
				cout<<1;
				if(cha1==cha2+1||cha1==cha2-1)
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
				cout<<0<<0;
			}
		}
		else
		{
			cout<<0<<0<<0;
		}
	}
	else
	{
		cout<<0<<0<<0<<0;
	}
	return 0;
}
