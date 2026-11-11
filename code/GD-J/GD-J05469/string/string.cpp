#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	string s1="",s2="";
	int len=0;
	for(int i=1;i<=n;i++)
	{
		int x;
		char y;
		cin>>x>>y;
		for(int j=1;j<=x;j++)
		{
			s1=s1+y;
			s2=y+s2;
		}
		len+=x;
	}
	int ans=0;
	for(int i=0;i<len;i++)
	{
		if(s1[i]!=s2[i])
		{
			ans++;
		}
	}
	ans/=2;
	cout<<ans;
	return 0;
}
