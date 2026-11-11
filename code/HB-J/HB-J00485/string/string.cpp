#include<bits/stdc++.h>
using namespace std;
struct para
{
	long long num;
	char c;
}a[200005];
string s;
long long cnt;
int abs1(int a)
{
	if(a>=0)
	{
		return a;
	}
	return -a;
}
int hw(string a)
{
	for(int i=0,j=a.size()-1;i<=j;i++,j--)
	{
		if(a[i]!=a[j])
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long maxn=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].num>>a[i].c;
		maxn=max(maxn,a[i].num);
	}
	if(n<=1e4&&maxn<=1e9)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=a[i].num;j++)
			{
				s+=a[i].c;
			}
		}
		if(hw(s)==1)
		{
			cout<<0<<endl;
			return 0;
		}
		else
		{
			for(int i=0,j=s.size()-1;i<=j;i++,j--)
			{
				if(s[i]!=s[j])
				{
					cnt++;
				}
			}
			cout<<cnt<<endl;
			return 0;
		}
	}
	else
	{
		if(n%2==0)
		{
			int i=1,j=n;
			for(int i=1,j=n;i<=j;i++,j--)
			{
				if(a[i].c!=a[j].c&&a[i].num!=a[j].num)
				{
					cnt+=min(a[i].num,a[j].num);
				}
				if(a[i].c!=a[j].c&&a[i].num==a[j].num)
				{
					cnt+=a[i].num;
				}
			}
			cout<<cnt<<endl;
		}
		else
		{
			int i=1,j=n;
			for(int i=1,j=n;i<=j;i++,j--)
			{
				if(a[i].c!=a[j].c&&a[i].num!=a[j].num)
				{
					cnt+=min(a[i].num,a[j].num);
					//cout<<"|"<<cnt<<endl;
				}
				if(a[i].c!=a[j].c&&a[i].num==a[j].num)
				{
					cnt+=a[i].num;
					//cout<<"&"<<cnt<<endl;
				}
			}
			//cout<<i<<endl;
			cnt+=abs1(a[i].num-1);
			cout<<cnt<<'\n';
		}
	}
	return 0;
}
