#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],sum=0;
long long aim=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	sort(a,a+n);
	aim=sum/n;
	for(int i=0;i<n;i++)
	{
		a[i]=labs(a[i]-aim);
	}
	sort(a,a+n);
	aim=a[0];
	long long ans=0;
	for(int i=0;i<n;i++)
	{
		a[i]-=aim;
		if(m>a[i]||m==a[i])
		{
			m-=a[i];
			ans++;
		}
		else
		{
			break;
		}
	}
	cout<<ans;
	return 0;
}
