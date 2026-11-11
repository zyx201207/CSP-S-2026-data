#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long n,m,sum=0,ans=1,ma,num=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		ma=a[i];
		sum=0;
		ans=1;
		for(int j=i+1;j<=n;j++)
		{
			if(sum+a[j]-a[i]<=m&&(ma+a[j]+m)/(j-i+1)>=a[j])
			{
				sum+=a[j]-a[i];
				ma+=a[j];
				ans++;
				if(a[j]==a[j-1])
				{
					ans++;
					continue;
				}
				continue;
			}
			break;
		}
		num=max(num,ans);
	}
	cout<<num;
	return 0;
	
}
