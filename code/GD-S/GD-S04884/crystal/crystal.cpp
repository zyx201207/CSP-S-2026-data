#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans,need,b[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		b[i]=b[i-1]+a[i];
	}
	int l=1;
	for(int r=2;r<=n;r++)
	{
		need=(long long)(a[r]*(r-l)-(b[r-1]-b[l-1]));
		if(need>m)
		{
			while(need>m)
			{
				l++;
				need=(long long)(a[r]*(r-l)-(b[r-1]-b[l-1]));
			}
		}
		if(r-l+1>ans) ans=r-l+1; 
	}
	cout<<ans;
	return 0;
}
