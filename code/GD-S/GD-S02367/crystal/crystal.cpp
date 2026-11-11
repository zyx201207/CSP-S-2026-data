#include<bits/stdc++.h>
using namespace std;
int n,ans,a[500005],d[5005];
long long m; 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	if(n==1)	ans=1;
	else if(m==0)
	{
		sort(a+1,a+n+1);
		int i=1,cnt=1;
		while(i<n)
		{
			if(a[i]==a[i+1])	cnt++;
			else
			{
				ans=max(ans,cnt);
				cnt=1;
			}
			i++;
		}
		ans=max(ans,cnt);
	}
	else if(m>1e8)
	{
		int d=a[2]-a[1],s=a[1],i=n;
		while(i>=0)
		{
			long long p=(2*s+(i-1)*d)*i;
			if(2*m>=p)	break;
		}
		ans=i+1;
	}
	else
	{
		long long sum=0;
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)	
		{
			d[i]=a[i]-a[i-1];
			sum+=(d[i]-d[i-1])*(i-1);
			if(sum>m)
			{
				ans=i-1;
				break;
			}
		}
	}
	cout<<ans;
	return 0;	
} 
