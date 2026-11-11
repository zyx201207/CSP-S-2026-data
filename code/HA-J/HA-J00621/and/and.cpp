#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200000+10],b[200000+10];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==m)
	{
		int ans;
		for(int i=2;i<=n;i++)
		{
			ans=a[i-1]&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==1)
	{
		int max_ans=INT_MIN;
		for(int i=1;i<=n;i++)
		{
			max_ans=max(max_ans,a[i]);
		}
		cout<<max_ans;
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n-1;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				b[i]=a[i]&a[j];
			}
		}
		int max_ans1=INT_MIN;
		for(int i=1;i<=n;i++)
		{
			max_ans1=max(max_ans1,b[i]);
		}
		cout<<max_ans1;
		return 0;
	}
	return 0;
} 
