#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[500005],v[500005],f;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	int num=m; 
	int ans=1;
	int t=0;
	for(int i=n-1;i>=0;i--)
	{
	    for(int j=i-1;j>=0;j--)
		{
			num=num-(a[i]-a[j]);
			if(num>=0)
		   {
			   ans++;
	     	}
	    }
		if(ans>t)
		{
			t=ans;
		}
		ans=1;
		num=m;
	}
	cout<<t;
	return 0;
} 
