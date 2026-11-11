#include <bits/stdc++.h> 
using namespace std;
int main()
{
	fropen("string.in","r",stdin);
	fropen("string.out","w",stdout);
	int n,c=0;
	string s=" ";
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		int m;
		char a;
		cin>>m>>a;
		for (int j=1;j<=m;j++)
		{
			s=s+a;
		}
	}
	if (s.size()%2==0)
	{
		for (int i=0;i<=(s.size()/2-1);i++)
		{
			if (s[i]!=s[s.size()-i-1])
			{
				c++;
			}
		}
	}
	else
	{
		for (int i=0;i<=(s.size()/2);i++)
		{
			if (s[i]!=s[s.size()-i-1])
			{
				c++;
			}
		}
	}
	cout<<c;
	return 0;
}
