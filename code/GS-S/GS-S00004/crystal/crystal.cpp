#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,jz=1;
	cin>>n>>m;
	int a[n+5],b[n+5];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{		
		int js=0,m2=m;
		if(a[i]-a[i-1]>m)
		{
			break;
		}
		for(int j=0;j<=i;j++)
		{
			if(a[i]-a[j]<=m2)
			{
				js++;
				m2-=a[i]-a[j];
			}
			else
			{
				break;
			}
		}
		jz=max(js,jz);
	}
	cout<<jz;
	return 0;
}
