#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],sum[200005][35],len,dow,tmp,ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];	
	}
	for (int i=1;i<=n;i++)
	{
		len=0;
		tmp=a[i];
		while(tmp)
		{
			len++;
			sum[i][len]=tmp%2;
			tmp/=2;
		}
	}
	for (int j=1;j<=30;j++)
	{
		for (int i=1;i<=n;i++)
		{		
			sum[i][j]+=sum[i-1][j];
		}
	}
	for (int pos=30;pos>=1;pos--)
	{
		if (sum[n][pos]>=m)
		{
			len=0;
			for (int i=1;i<=n;i++)
			{
				if (sum[i][pos]-sum[i-1][pos]==1)
				{
					len++;
					for (int j=1;j<=30;j++)
					{
						sum[len][j]=sum[i][j]-sum[i-1][j];
						sum[len][j]+=sum[len-1][j];
					}
				}
			}
			n=len;
			ans*=2;
			ans++;
		}
		else
		{
			ans*=2;
		}
	}
	cout<<ans;
	return 0;
}
