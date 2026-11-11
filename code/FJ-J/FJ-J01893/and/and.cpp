#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n;
	cin>>n;
	if(n==1)
	{
		cout<<0;
	}
	string s;
	for(int i=1;i<=n;i++)
	{
		int m;
		string a;
		cin>>m>>a;
		for(int j=1;j<=m;j++)
		{
			s+=a;
		}
	}
	int sum=0;
	int b=s.size();
	string s2;
	for(int i=1;i<=s.size();i++)
	{
		s2+='a';
	}
	for(int i=0;i<s.size();i++)
	{
		if(s2[i]!=s[i])
		{
			s2[i]=s[i];
			if(s2[b-i]!=s[i])
			{
				s2[b-i]=s[i];
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}
