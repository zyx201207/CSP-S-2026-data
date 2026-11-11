#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans,mxans;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	if(m==1)
		cout<<a[n-1];
	else if(m==n)
	{
		ans=a[0];
		for(int i=1;i<n;i++)
			ans=ans&a[i];
		cout<<ans;
	}
	else if(m==2)
	{
		int l=0,r=1;
		for(int i=0;i<n-1;i++)
			for(int j=i+1;j<n;j++)
				ans=max(ans,a[i]&a[j]);
		cout<<ans;
	}
	else
	{
		int j=n-2;
		ans=a[n-1],m--;
		while(m--)
		{
			ans&=a[j];
			j--;
		}
		cout<<ans;
	}
	return 0;
}
