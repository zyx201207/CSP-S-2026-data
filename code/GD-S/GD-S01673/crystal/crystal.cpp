#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,mx=1;
	cin>>n>>m;
	int a[n],s[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<n;i++)
	{
		s[i]=a[i]-a[i-1]+s[i-1];
	}
	for(int i=0;i<n-1;i++)
	{
		int t=0;
		for(int j=i;j>=0;j++)
		{
			t+=(s[i]-s[j]);
			if(t>m)
			{
				break;
			}else
			{
				mx=max(i-j+2,mx);
			}
		}
	}
	cout<<mx;
	return 0;
}
