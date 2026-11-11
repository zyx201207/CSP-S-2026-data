#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,m,ans,k,cnt,mmc;
bool check(int x)
{
	long long xum=1;
	for(int i=1;i<=30;i++)
	{
		xum*=2;
		if(x==xum)return false;
	}
	return true;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	k=n;
	ans=-1;
	mmc=m;
	for(int i=n;i>=1&&m;i--)
	{
		if(a[i]>k/2&&check(a[i]))
		{
			m--;
			if(ans==-1)
			ans=a[i];
			else
			ans=ans&a[i];
		}
		else
		{
			k=k/2;
		}
	}
	if(m)
	{
		int zb=-114514;
		for(int i=1;i<=n;i++)
		{
			if(ans>a[i])
			zb=i;
			else
			{
				break;
			}
		}
		for(int i=zb;i>=1;i--)
		{
			m--;
			ans=ans&a[i];
		}
		if(ans==-1)
		{
			ans=a[n];
			for(int i=n-1;i>=1&&m;i--)
			{
				m--;
				ans=ans&a[i];
			}
			cout<<ans;
			return 0;
		}
		if(m||zb==-114514)
		cout<<0;
		else cout<<ans;
		return 0;
	}
	if(mmc==0)cout<<0;
	else
	cout<<ans;
}
