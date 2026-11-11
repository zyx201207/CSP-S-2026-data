#include<bits/stdc++.h>
using namespace std;
long long a[500005],cnt[500005],b[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	if(n<=5000)
	{
		for(int j=1;j<=n;j++)
		{
			memset(cnt,0,sizeof cnt);
			for(int i=j+1;i<=n;i++)
				cnt[i]=(a[i]-a[i-1])*(i-1);
			for(int i=j+1;i<=n;i++)
				cnt[i]+=cnt[i-1];
			long long maxx=0;
			for(int i=n;i>=j;i--)
				if(cnt[i]<=m)
				{
					maxx=i-j+1;
					break;
				}
	//		for(int i=1;i<=n;i++)
	//			cout<<a[i]<<' ';
	//		cout<<endl;
	//		for(int i=1;i<=n;i++)
	//			cout<<cnt[i]<<' ';
	//		cout<<endl;
			ans=max(ans,maxx);
	//		cout<<ans<<' '<<maxx<<endl; 
		}
		cout<<ans;
	}
	else
	{
		for(int i=2;i<=n;i++)
			cnt[i]=(a[i]-a[i-1])*(i-1);
	//	for(int i=1;i<=n;i++)
	//		cout<<a[i]<<' ';
		for(int i=2;i<=n;i++)
			cnt[i]+=cnt[i-1];
	//	for(int i=1;i<=n;i++)
	//		cout<<cnt[i]<<' ';
		for(int i=n;i>=1;i--)
			if(cnt[i]<=m)
			{
				cout<<i;
				return 0;
			}
	}
	return 0;
} 
//	int p=n,sum=a[n],ans=1;
//	for(int i=n;i>=1;i--)
//	{
//		sum-=a[i];
//		while((i-p+1)*a[i]-sum-)
//	}
