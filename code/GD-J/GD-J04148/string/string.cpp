#include<bits/stdc++.h>
using namespace std;
long long n,sum[200010],a[200010];
char b[200010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		sum[i]=sum[i-1]+a[i];
	}
	int cmp=sum[n]/2;
	for(int i=1;i<=n;i++)
	{
		if(sum[i]>cmp)
		{
				int t=sum[i]-cmp;
				if(sum[n]%2==0)
				{
					for(int j=n;j>=i;j--)
					{
						a[j+1]=a[j];
					}
					for(int j=n;j>=i;j--)
					{
						b[j+1]=b[j];
					}
					a[i+1]=t;
					a[i]-=t;
					n++;
				}
				else
				{
					for(int j=n;j>=i;j--)
					{
						a[j+1]=a[j];
					}
					for(int j=n;j>=i;j--)
					{
						b[j+1]=b[j];
					}
					for(int j=n+1;j>=i+1;j--)
					{
						a[j+1]=a[j];
					}
					for(int j=n+1;j>=i+1;j--)
					{
						b[j+1]=b[j];
					}
					a[i+2]-=((a[i+2]-t)+1);
					a[i+1]=1;
					a[i]-=t;
					n+=2;
				}
				break;
		}
	}
	int l=1,r=n;
	long long ans=0;
	while(l!=r)
	{
		int tmp=min(a[l],a[r]);
		if(b[l]!=b[r])
		{
			ans+=tmp;
		}
		a[l]-=tmp;
		a[r]-=tmp;
		if(a[l]==0)
		{
			l++;
		}
		else
		{
			r--;
		}
	}
	cout<<ans;
	return 0;
}
