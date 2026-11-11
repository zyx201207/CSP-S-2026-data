#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int t;
long long a[N];
char b[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	bool flag=true;
	int s;
	int x,y;
	for (int i=1;i<=t;i++)
	{
		cin>>a[i]>>b[i];
		if (i>1)
		{
			if (b[i]!=b[i-1])
			{
				flag=false;
				s++;
				x=i-1,y=i;
			}
		}
	}
	if (flag==true)
	{
		cout<<0;
		return 0;
	}
	else if (s==1)
	{
		long long sum=0;
		long long num=0;
		for (int i=1;i<=x;i++)
		{
			sum+=a[i];
		}
		for (int i=y;i<=t;i++)
		{
			num+=a[i]; 
		}
		if (sum<=num)
		{
			cout<<sum;
		}
		else
		{
			cout<<num;
		}
		return 0;
	}
	else if (t==1)
	{
		cout<<0;
		return 0;
	}
	else if (t==2)
	{
		if (a[1]<=a[2])
		{
			cout<<a[1];
		}
		else
		{
			cout<<a[2];
		}
		return 0;
	}
	else
	{
		string ans="";
		for (int i=1;i<=t;i++)
		{
			for (int j=1;j<=a[i];j++)
			{
				ans+=b[i];
			}
		}
		long long d=ans.size();
		d/=2;
		d+=1;
		string num="";
		for (int i=0;i<=d-2;i++)
		{
			num+=ans[i];
		}
		int total=0;
		for (int i=0;i<=d-2;i++)
		{
			if (num[i]!=ans[ans.size()-i-1])
			{
				total++;
			}
		}
		cout<<total;
		return 0;
	}
	return 0;
}
