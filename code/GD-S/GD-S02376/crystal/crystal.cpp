#include <bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],sum[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	//scanf("%d%ll",n,m);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
	}
	sort(a+1,a+n+1);
	int l=1;
	long long ans=1;
	sum[0]=0;
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	//cout<<a[5];
	for(int r=2;r<=n;r++)
	{
		//cout<<l;
		while(l<r)
		{
			long long need=(r-l)*a[r]-sum[r-1]+sum[l-1];
			//cout<<need<<" ";
		    if(need<=m) 
		    {
			    ans=max(ans,(long long)r-l+1);
			    //cout<<need<<' ';
			    break;
		    }
		    else if(need>m)
		    {
			    //cout<<l;
				l++;
		    }
		}
	}
	cout<<ans;
	return 0;
}
