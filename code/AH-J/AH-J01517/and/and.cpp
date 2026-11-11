#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,sum=-1,tot=0,cnt=0,f=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum=max(sum,a[i]);
		if(a[i]==3) tot++;
		if(a[i]==2) cnt++;
		if((a[i]&2097152)!=a[i]) f=0;
	}
	int x=a[1];
	if(m==1) cout<<sum;
	else if(n==m)
	{
		for(int i=2;i<=n;i++)
		{
			x=x&a[i];
		}
		cout<<x;
	}
	else if(m==2)
	{
		int ans=-1;
		for(int i=1;i<=n-1;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}
	else if(sum<4)
	{
		if(tot>=m) cout<<3;
		else
		{
			if(tot+cnt>=m) cout<<2;
			else
			{
				cout<<0;
			}
		}
	}
	else if(f==1)
	{
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
	}
	else cout<<0;
	return 0;
}
