#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a,q=1,f=0;
	string s[100000005],d;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>d;
		f+=a;
		for(int j=1;j<=a;j++)
		{
			s[q]=d;
			q++;
		}
	}
	if(n==1)
	{
		cout<<0;
	}
	string s1[1000000005];
	for(int i=n;i>=1;i--)
	{
		s1[i]=s[n-i+1];
	}
	if(s1==s)
	{
		cout<<0;
	}
	else
	{
		cout<<f/2;
	}
	return 0;
}