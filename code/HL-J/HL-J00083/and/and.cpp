#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans=-1;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1)
	{
	    ans=a[n];
	}
	else if(m==2)
	{
        for(int i=1;i<=n;i++)
        {
        	for(int j=i+1;j<=n;j++)
			{
				ans=max((a[i]&a[j]),ans);
			}
		}
	}
	else if(m==n)
	{
		int t=a[1];
		for(int i=2;i<=n;i++)
		{
			t=t&a[i];
		}
		ans=t;
	}
	else
	{
		int t=a[n];
		for(int i=2;i<=m;i++)
		{
			t=(t&a[n-i+1]);
		}
		ans=t;
	}
	cout<<ans<<'\n';
	return 0;
}