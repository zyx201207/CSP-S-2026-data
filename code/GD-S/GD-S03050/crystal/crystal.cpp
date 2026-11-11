#include<bits/stdc++.h>
using namespace std;
long long n,m,a[555555],b[555555],ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)
	{
		b[i]=a[i]-a[i-1]+b[i-1];
	}
	long long l=0,r=1;
	while(l<n&&r<=n)
	{
		if(b[r]-b[l]<=m)
		{
			ans=max(ans,r-l);
			r++;
		}
		else
		{
			l++;
		}
	}
	cout<<ans;
 } 
