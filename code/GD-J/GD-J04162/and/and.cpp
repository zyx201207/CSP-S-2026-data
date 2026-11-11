#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],q,p=0,o,l;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=2;j<=n;j++)
		{
			q=a[j]&a[j-1];
			if(q>p)
			{
				p=q;
				o=j;
				l=j-1;
			}
		}
		a[o]=0;
		a[l]=0;
	}
	cout<<p;
} 
