#include<bits/stdc++.h>
using namespace std;
string s="";
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++)
		{
			s+=c;
		}
	}
	int sum=0;
	if(s.size()%2==1)
	{
		for(int i=0;i<s.size()/2;i++)
		{
			if(s[i]!=s[s.size()-i-1])
			{
				sum++;
			}
		}
	}
	else
	{
		for(int i=0;i<s.size()/2-1;i++)
		{
			if(s[i]!=s[s.size()-i-1])
			{
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}

