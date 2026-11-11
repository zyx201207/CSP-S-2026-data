#include <bits/stdc++.h>
using namespace std;
long long s[20000005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,b;
	cin>>a>>b;
	for(int i=1;i<=a;i++)
	{
		cin>>s[i];
	}
	long long maxx=0;
	if(b==1)
	{
		for(int i=1;i<=a;i++)
		{
			maxx=max(maxx,s[i]);
		}
		cout<<maxx;
	}
	if(b==2)
	{
		for(int i=1;i<=a;i++)
		{
			for(int k=i+1;k<=a;k++)
			{
				long long q=s[i]&s[k];
				maxx=max(maxx,q);
			}
		}
		cout<<maxx;
		return 0;
	}
	if(b==3)
	{
		for(int i=1;i<=a;i++)
		{
			for(int k=i+1;k<=a;k++)
			{
				for(int l=k+1;l<=a;l++)
				{
					long long q=s[i]&s[k]&s[l];
					maxx=max(maxx,q);
				}
			}
		}
		cout<<maxx;
		return 0;
	}
	if(b==4)
	{
		for(int i=1;i<=a;i++)
		{
			for(int k=i+1;k<=a;k++)
			{
				for(int l=k+1;l<=a;l++)
				{
					for(int j=l+1;j<=a;j++)
					{
						long long q=s[i]&s[k]&s[l]&s[j];
						maxx=max(maxx,q);
					}
				}
			}
		}
		cout<<maxx;
		return 0;
	}
	if(b==5)
	{
		for(int i=1;i<=a;i++)
		{
			for(int k=i+1;k<=a;k++)
			{
				for(int l=k+1;l<=a;l++)
				{
					for(int j=l+1;j<=a;j++)
					{
						for(int o=j+1;o<=a;o++)
						{
							long long q=s[i]&s[k]&s[l]&s[j];
							maxx=max(maxx,q);
						}
					}
				}
			}
		}
		cout<<maxx;
		return 0;
	}
	if(b==a)
	{
		for(int i=1;i<=a;i++)
		{
			maxx=maxx&s[i];
		}
		cout<<maxx;
		return 0;
	}
	return 0;
}
