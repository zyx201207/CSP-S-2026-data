#include<bits/stdc++.h>
using namespace std;
int n,m,maxn;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==1) cout<<maxn<<endl;
	else if(m==n)
	{
		int res=a[1];
		for(int i=2;i<=n;i++)
		{
			res=res&a[i];
		}
		cout<<res<<endl;
	}
	else if(m==2)
	{
		int res=0,tmp=0,ma=0;
		for(int i=1;i<=n;i++)
		{
			res=a[i];
			tmp=a[i];
			for(int j=1;j<=n&&j!=i;j++)
			{
				tmp=tmp&a[j];
				ma=max(ma,tmp);
				tmp=a[i];
			}
		}
		cout<<ma<<endl;
	}
	else
	{
		sort(a+1,a+n+1);
		cout<<a[n-m+1]<<endl;
	} 
	return 0;
}
