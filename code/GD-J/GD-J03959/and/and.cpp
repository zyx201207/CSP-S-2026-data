#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool d[200005],l[200005],b,c;
int n,m,cnt,ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		l[i]=1;
	}
	for (int i=29;i>=0;i--)
	{
		cnt=0;
		for (int j=1;j<=n;j++)
		{
			if (!d[j]&&b) l[j]=0;
			d[j]=0;
			if ((a[j]&(1<<i))&&l[j])
			{
				d[j]=1;
				cnt++;
			}
		}
		//if (i==4)
		//cout<<cnt<<" ";
		if (cnt==m)
		{
			c=0;
			for (int j=1;j<=n;j++)
			{
				if (!c&&d[j]) 
				{
					ans=a[j];
					c=1;
				}
				if (d[j])
				ans=a[j]&ans;
			}
			cout<<ans;
			return 0;
		}
		if (cnt>m)
		{
			b=1;
			ans+=(1<<i);
		}
		else b=0;
		//cout<<ans<<" ";
	}
	cout<<ans;
	return 0;
}
