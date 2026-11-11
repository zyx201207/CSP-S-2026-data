#include <bits/stdc++.h>
using namespace std;
string s,b;
int main()
{
	int n,x,sum=0;
	cin>>n;
	string b;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>b;
		for(int j=1;j<=x;j++)
		{
			s+=b;
		}
	}
	
	for(int i=s.length()-1;i>=0;i--)
	{
		for(int j=0;j<=s.length()-1;j++)
		{
			if(s[i]!=s[j])
			{
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}
