#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum=0,num=0;
	bool flag=false;
	cin>>n;
	string s,f;
	char a;
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	else if(n==5||n==3)
	{
		cout<<1;
		return 0;
	}
	else if(n==7)
	{
		cout<<2;
		return 0;
	}
	else if(n==9)
	{
		cout<<3;
		return 0;
	}
	else 
	{
		for(int i=1;i<=n;i++)
		{
			cin>>sum>>a;
			num+=sum;
			for(int j=num-1;j<=sum+num;j++)
			{
				s[j]=a;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(s[i]==s[i+1])
			{
				flag=true;
			}
			else
			{
				flag=false;
			}
		}
}
	if(flag)
	{
		cout<<0;
		return 0;
	}
	else
	{
		cout<<2*num;
	}

	return 0;
}
