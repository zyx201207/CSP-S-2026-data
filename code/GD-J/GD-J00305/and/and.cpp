#include <bits/stdc++.h>
using namespace std;

int a[100005];
int MAXN=0;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		for(int i=0;i<n;i++)
		{
			MAXN=max(MAXN,a[i]);
		}
	}
	else if(m==n)
	{
		MAXN=a[0];
		for(int i=1;i<n;i++)
		{
			MAXN=MAXN&a[i];
		}
	}
	else if(m==2)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=1;j<n;j++)
			{
				if(i!=j)
				{
					MAXN=max(MAXN,a[i]&a[j]);
				}
			}
		}
	}
	cout<<MAXN;
	return 0;
}
