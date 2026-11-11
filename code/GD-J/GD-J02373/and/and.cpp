#include<bits/stdc++.h>
using namespace std;
int n,m;
long long maax=0;
long long a[200005];
void find(int step,int use,long long sum)
{
	if(step==n+1)
	{
		return ;
	}
	if(use==m)
	{
		maax=max(maax,sum);
	}
	find(step+1,use+1,sum&a[step+1]);
	find(step+1,use,sum);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long maxn=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]; 
		maxn=max(maxn,a[i]);
	} 
	if(m==1)
	{
		cout<<maxn<<endl;
		return 0;
	}
	long long max2=0;
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i!=j)
				{
					max2=max(max2,a[i]&a[j]);
				}
			}
		}
		cout<<max2<<endl;
		return 0;
	}
	if(n==m)
	{
		for(int i=2;i<=n;i++)
		{
			a[i]=a[i-1]&a[i];
		}
		cout<<a[n]<<endl;
		return 0;
	}
	for(int i=1;i<=n-m+1;i++)
	{
		find(i,1,a[i]);
	}
	cout<<maax<<endl;
	return 0;
}
