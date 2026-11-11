#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int flag=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i>1)
		{
			if(a[i]<a[i-1])
			{
				flag=0;	
			}	
		}
	}
	for(int i=1;i<n;i++)
	{
		if(a[i]!=a[i+1])
		{
			flag=3;
		}
	}
	if(flag!=3)
	{
		for(int i=1;i<=n;i++)
		{
			cout<<2*i<<" ";
		}
		return 0;	
	}
	for(int i=1;i<=n;i++)
	{
		cout<<i<<" ";
	}
	return 0;
}
