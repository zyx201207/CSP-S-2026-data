#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxx=0,ok=1;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int j=n;j>=1;j--)
	{
		ok=1;
		for(int i=1;i<=30;i++)
		{
			if(a[j]>pow(2,i))
			{
				break;
			}
			else if(a[j]==pow(2,i))
			{
				ok=0;
				break;
			}
		}
		if(ok==1)
		{
			maxx=a[j];
			break;
		}
	}
	for(int i=1;i<=m-1;i++)
	{
		maxx&=a[n-i];
	}
	cout<<maxx;
	return 0;
} 
