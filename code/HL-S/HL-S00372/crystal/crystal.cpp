#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500002];
ll sum[500002];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	ll sum=0;
	ll m;
	ll ans=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		ans+=a[i]; 
	}
	ans/=n;
	sort(a,a+n);
	if(a[n-1]*(n-1)<=m)
	{
		cout<<n;
		return 0;
	}
	ll mb=0,cha,mincha=100000000000;
	int mbi=0;
	for(int i=0;i<n;i++)
	{
		cha=abs(a[i]-ans);
		if(cha<mincha)
		{
			mincha=cha;
			mbi=i;
		}
		if(ans-a[i]==0)
		{
			mb=a[i];
			break;
		}
	}
	if(mb==0)
	{
		mb=a[mbi];
	}
	int p=n;
	while(m>0)
	{
		p--;
		if(a[p]==mb)
		{
			sum++;
		}
		else
		{
			if(a[p]>mb)
			{
				continue;
			}
			else
			{
				m-=mb-a[p];
				if(m>=0)
				{
					sum++;
				}
			}
		
		}
	}
	cout<<sum;
	return 0;
} 
