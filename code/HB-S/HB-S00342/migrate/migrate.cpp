#include<bits/stdc++.h>
using namespace std;
long long c,t,cnt,cnt2[2000005],maxn=-1e9;
long long x[2000005],n[2000005],d[2000005];

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i = 1;i<=t;i++)
	{
		cin>>n[i]>>d[i];
		d[i]=d[i]+1;
		for(int j = 1;j<=n[i];j++)
		{
			cin>>x[j];
			if(x[j]<0)
			{
				cnt2[i]++;
			}
		}
	}
	for(int i = 1;i<=t;i++)
	{
		cnt=0;
		for(int j = 1;j<=n[i];j++)
		{
			
			for(int k = 1;k<=n[i];k++)
			{
				int p=abs(x[k]-x[j]);
				if(p==d[i])
				{
					cnt++;
					maxn=max(maxn,cnt);
				}
				//cout<<x[k]-x[j]<<"ff"<<d[i]<<endl;
			}
			
		}
		if(cnt2[i]!=n[i]&&cnt2[i]>0)
		{
			maxn--;
		}
		if(maxn<0)
		{
			cout<<0<<endl;
		}
		else
		{
			cout<<maxn/2<<endl;
		}
		
	}
	return 0;
}
