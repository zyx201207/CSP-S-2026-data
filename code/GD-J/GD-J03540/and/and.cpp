#include <bits/stdc++.h>
using namespace std;
int n,m,a[200001],maxn,all,maxm;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i==1)all=a[i];
		else all&=a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==1)cout<<maxn;
	else if(m==n)cout<<all;
	if(m==2)
	{
		for(int i=1;i<n;i++)
		  for(int j=i+1;j<=n;j++)
		  {
		  	maxm=max(a[i]&a[j],maxm);
		  }
		cout<<maxm;
	}
}
