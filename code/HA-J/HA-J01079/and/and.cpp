#include<bits/stdc++.h>
using namespace std;
int a[200010];
int b[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	for(int j=0;j<m-1;j++)
	{
		for(int i=0;i<n;i++)
		{
			int ans=b[i]&a[i+1];
			for(int k=n-i;k<n;k++)
			{
				ans=max(ans,ans&a[k]);
			}
			b[i]=ans;
		}
	}
	int num=INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(b[i]>=num) num=b[i];
	}
	cout<<num;
}
