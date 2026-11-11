#include<bits/stdc++.h>
using namespace std;
int n;
long long a[1000000];
char c[1000000];
char cc[1000000];
bool f=true;
int j=1,ma;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.in","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int a1=a[1];
	int a2=a[2];
	for(int i=1;i<=100000;i++)
	{
		while(a[i]--)
		{
			cc[j]=c[i];
			j++;
		}
	}
	if(n==1)
	{
		cout<<0<<endl;
		return 0;
	}
	else
	{
		for(int i=1;i<10000;i++)
		{
			if(cc[i])
			{
				if(cc[i]!=cc[i+1])
				{
					f=false;
				}
				ma=max(a1,a2);
			}
		}
		if(!f)
		{
			cout<<ma<<endl;
			return 0;
		}
		else
		{
			cout<<0<<endl;
		}
	}
	return 0;
}
