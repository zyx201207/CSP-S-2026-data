#include<bits/stdc++.h>
using namespace std;
int main()
{

	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string a="",b="";
	for(int i=0;i<s1.size()-1;i++)
	{
		a+=s1[i];
		b+=s2[i];
	}
	int len=s1.size()-1;
	if(c1==c2)
	{
		
		if(a==b)
		{
			if((s1[len]=='C'||s1[len]=='D')&&(s2[len]=='C'||s2[len]=='D'))
			{
				cout<<"1100";
			}
			else 
			{
				if((s1[len]+1==s2[len])||(s2[len]+1==s1[len]))
				{
					cout<<"1111";
				}
				else
				{
					cout<<"1110";
				}
			}
		}
		else
		{
			cout<<"1000";
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}
