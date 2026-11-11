#include<bits/stdc++.h>
using namespace std;
const int MAXN=5*1e5+20;
long long n,m,ans;
long long a[MAXN];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n<=5000)
	{
		for(int i=1;i<=n;i++)
	{
		long long k=m,sum=1;
		if(k-(a[i]-a[i-1])>=0)
		{
			for(int j=i-1;j>=1;j--)
	    {
		    if(k-(a[i]-a[j])>=0)
		    {
			    k-=(a[i]-a[j]);
			    sum++;
		    }
		    else
		    {
		    	break;
			}
	    }
		}
	    ans=max(ans,sum);
	}
	cout<<ans;
	}
	else
	{
		if(a[1]==a[2])
		cout<<n;
		else
		{
			long long sum=1,k=1;
			while(m-(k*(a[2]-a[1]))>=0)
			{
				m-=k*(a[2]-a[1]);
				sum++;
				k++;
			}
			cout<<sum;
		}
	}
	return 0;
}
