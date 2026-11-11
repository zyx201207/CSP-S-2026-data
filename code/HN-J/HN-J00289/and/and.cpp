#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005],ans=0,L[200005],R[200005],d[200005];
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int o=0,oo=n,f=0;
	while(oo)
	{
		if(oo%2!=0&&oo!=1)
		{
			f=1;
			break;
		}	
		else
		{
			o++;
		}
		oo/=2;
	}
	d[1]=2;
	for(int i=2;i<=30;i++)
		d[i]=d[i-1]*2;
	if(m==1)
	{
		sort(a+1,a+n+1,cmp);
		cout<<a[1]<<endl;
		return 0;
	}
	else if(m==n)
	{
		sort(a+1,a+n+1,cmp);
		ans=a[1];
		for(int i=2;i<=n;i++)
			ans&=a[i];
	}
	else if(m==n-1)
	{
		L[1]=a[1];
		for(int i=2;i<n;i++)
			L[i]=L[i-1]&a[i];
		R[n]=a[n];
		for(int i=n-1;i>=2;i--)
			R[i]=R[i+1]&a[i];
		for(int i=1;i<=n;i++)
		{
			ans=max(ans,L[i-1]&R[i+1]);
		}
		cout<<ans;
	}
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
				ans=max(ans,a[i]&a[j]);
		}
		cout<<ans;
	}
	else if(f==0)
	{
		for(int i=o-1;i>=1;i--)
		{
			if((1<<i)-(1<<(i-1))>=m)
				ans+=(1<<i);
		}
		cout<<ans;
	}
	else
	{
		sort(a+1,a+n+1,cmp);
		ans=a[1];
		for(int i=2;i<=m;i++)
			ans&=a[i];
		cout<<ans;
	}
	return 0;
 } 

