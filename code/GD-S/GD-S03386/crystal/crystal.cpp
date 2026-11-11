#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];

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
	long long cntm,cntn,ans=0;
	for(int i=1;i<=n;i++)
	{
		long long cnt=0;
		for(int j=i;j<=n;j++)
		{
			if(a[j]==a[i]) cnt++;
			else 
			{
			    break;
			}
		}
		ans=max(cnt,ans);
	}
	for(int i=1;i<=n;i++)
	{
		cntm=0,cntn=0;
        for(int j=1;j<=i;j++)
        {
        	cntm+=a[i]-a[j];
        	cntn++;
        	if(cntm>m)
		    {
		        break;
		    }
		}
		if(cntm<=m)
		{
			ans=max(cntn,ans);
		}
	}
	cout<<ans;
 } 
