#include<bits/stdc++.h>
using namespace std;
long long i,j,n,m,a[100001],maxn,maxn1; 
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(a[i],maxn);
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i!=j)
			{
				maxn1=max(a[i]&a[j],maxn1);
			}
		}
	}
	if(m==1)
	{
		cout<<maxn;
	}
	else
	{
		cout<<maxn1;
	}
}
