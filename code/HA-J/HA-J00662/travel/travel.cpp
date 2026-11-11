#include<iostream>
#include<string>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	bool tx=0,tp=0,tc=0,xl=0;
	if(c1==c2)
	{
		tx=1;
	}
	for(int i=0;i<s1.size();i++)
	{
		for(int j=0;j<s2.size();j++)
		{
			if(i==j)
			{
				tp=1;
			}
			for(char c:s1)
			{
				for(char c:s2)
				{
					if(i==j&&s1>='A'&&s1<='C'&&s2>='A'&&s2<='C'||s1>='D'&&s1<='F'&&s2>='D'&&s2<='F')
					{
						tc=1;
					}
					if(i+1==j||i-1==j)
					{
						xl=1;
					}
				}
			}			
		}
	}
	cout<<tx<<tp<<tc<<xl;
	return 0;
}

