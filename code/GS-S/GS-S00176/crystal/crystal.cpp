#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	int n,m=0,i,count=0;
	cin>>n>>m;
	int a[n];
	for(i=0;i<=n-1;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n+1);
	for(int i=0;i<=n-1;i++)
	{
		if(a[i]==a[i+1])
		{
			count++;
			i=i+2;
		}
		else
		{
			if(a[i+1]-a[i]<=m)
			{
			count++;
			m=a[i+1]-a[i];
			}
		}
	}
	cout<<count;
	return 0;
 }
