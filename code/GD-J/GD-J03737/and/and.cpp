#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,s=0;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int c=a[i]|a[j];
			if(c>s)
			{
				s=c;
			}
		}
	}
	cout<<s;
	return 0;
}
