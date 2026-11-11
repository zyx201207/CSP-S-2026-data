#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==11 || c==12)
	{
		for(int gh=1;gh<=t;gh++)
		{
			int n,d;
			cin>>n>>d;
			int gu=2*1ll*d-1;
			int cur=0;
			long long sum=0;
			for(int i=1;i<=n;i++)
			{
				cin>>a[i];
				sum=a[i]-a[1];
				if(sum>=gu)
				{
					if(sum==gu)
					{
						cur=i;
					}
					break;
				}
			}
			if(cur==0)
			{
				cout<<"0"<<endl;
			}
			else
			{
				cout<<n-cur+1<<endl;
			}
		}
	}
	if(c<=10)
	{
		for(int gh=1;gh<=t;gh++)
		{
			int n,d;
			cin>>n>>d;
			for(int i=1;i<=n;i++)
			{
				cin>>a[i];
			 } 
			int ans=0;
			int gu=2*1ll*d-1;
			for(int i=1;i<=n-gu;i++)
			{
				if(a[i+gu]-a[i]==gu)
				{
					ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
