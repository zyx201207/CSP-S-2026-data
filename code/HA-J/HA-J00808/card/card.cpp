#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m;
int a[N],tong[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++)
	{
		bool op;
		int j1;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]==a[i])
			{
				op=0;
			}
			else
			{
				op=1;
			}
			j1=j;
		}
		if(op==1)				
		for(int k=i;k<=n;k++)
		{
			tong[a[k]]++;
		}
		if(op==0)
		for(int k=j1;k<=n;k++)
		{
			tong[a[k]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<tong[i]<<" ";
	}
	return 0;
}
