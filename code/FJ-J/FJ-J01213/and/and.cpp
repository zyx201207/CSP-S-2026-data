#include <bits/stdc++.h>
using namespace std;

int n,m,a[200005],MAX,ans=1;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >>n >>m;
	for(int i=1;i<=n;i++)
	{
		cin >>a[i];
	}
	for(int i=1;i<=30;i++)
	{
		ans|=(ans<<1);
	}
	if(m==1)                    //²âÊÔµã6 
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]>=MAX)
			{
				MAX=a[i];
			}
		}
		cout <<MAX;
		return 0;
	}
	else if(m==n)               //²âÊÔµã7 
	{
		for(int i=1;i<=n;i++)
		{
	        ans&=a[i];
		}
		cout <<ans;
	}
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(MAX<=(a[i]&a[j]))
				{
					MAX=(a[i]&a[j]);
				}
			}
		}
		cout <<MAX;
		return 0;	
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]>=MAX)
			{
				MAX=a[i];
			}
		}
		cout <<MAX;
	}
	return 0;
}








































//AC!
