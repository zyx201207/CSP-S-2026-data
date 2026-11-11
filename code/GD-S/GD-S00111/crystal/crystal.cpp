#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m1;
	cin>>n>>m1;
	int a[n+1];
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];	
	}	
	sort(a+1,a+n+1);
	int b[n+1]={};
	for(int i=1;i<=n;i++)
	{
		int mid=i;
		int ans=1;
		int m=m1;
		for(int j=i-1;j>=1;j--)
		{
			if(abs(a[i]-a[j])<=m)
			{
				ans++;
				m-=abs(a[i]-a[j]);
			}
		}
		b[i]=ans;
	} 
	sort(b+1,b+n+1);
	cout<<b[n]<<" ";
	return 0;
} 
