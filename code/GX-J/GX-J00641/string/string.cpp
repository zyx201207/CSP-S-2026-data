#include<bits/stdc++.h>
using namespace std;

int main()
{
	freeopen("string.in","r",stdin);
	freeopen("string.out,"w",stdout);
	long long  n,c;
	char a;
	cin>>n;
	for(int i=1;i<=n;i++;)
	{
		cin>>c;
		cin>>a;
	}
	long long s=n*c;
	long long d[n*10e9];
	for(int i=1;i<=s;i++)
	{
		cin>>d[i];
	}
	long long g=s/2+1;
	long long v=s/2;
	long long p=0;
	if(s%2==0)
	{
		for(int i=d[1];i<=v;i++)
		{
			for(int j=d[s];j>=v;j++)
			{
				if(d[i]!=d[j])
				{
					d[i]=d[j];
					p++;
				}
			}
		}
	}
	else
	{
		for(int i=d[1];i<=g;i++)
		{
			for(int j=d[s];j>=g;j++)
			{
				if(d[i]!=d[j])
				{
					d[i]=d[j];
					p++;
				}
			}
		}
	}
	cout<<p;
	return 0;
}
