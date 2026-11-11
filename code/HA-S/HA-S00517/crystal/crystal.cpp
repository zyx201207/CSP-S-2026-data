#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],maxx=-1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n*n<=200000000)
	{
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++)
		{
			long long t=m,cnt=1;bool f=0;
			for(int j=1;1;j++)
			{
				f=0;
				if(i-j>0)
				{
					if(a[i]-a[i-j]<=t)
					{
						t-=a[i]-a[i-j];
						cnt++;
						f=1;
					}
				}
				if(!f)break;
			}
			maxx=max(maxx,cnt);
			/*ceshi*/
	//		if(maxx==cnt)cout<<"mid is ";
	//		cout<<a[i]<<" ans:"<<cnt<<"\n";
		}
		cout<<maxx;
	}
	else
	{
		long long ans=0,k=abs(a[2]-a[1]),sum=0;
		for(int i=0;i<n;i++)
		{
			sum+=k*i;
			ans++;
			if(sum>m)
			{
				ans--;
				break;
			}
		}
		cout<<ans;
	}
	return 0;
}
