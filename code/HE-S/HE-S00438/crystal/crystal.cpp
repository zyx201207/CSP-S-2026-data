#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,b=0;
	int a[100000];
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		int c=a[i],e=i-1,f=0;
		for(int j=1;j<=m;j++)
		{
			int d=a[e];
			if(d=c)
			{
				e--;
				f++;
			}
			else if(d<c)
			{
				d++;
			}
		}
		if(f>b)
		{
			b=f;
		}
	}
	cout<<b;
	return 0;
}
