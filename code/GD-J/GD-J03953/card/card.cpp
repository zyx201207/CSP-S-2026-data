#include <bits/stdc++.h>
using namespace std;
int cnt[300005]={0};
int a[500005]={0};
bool f[500005]={0};
int b[500005]={0};
long long n,m;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=500005;j++)
		{
			f[i]=0;
			b[i]=0;
		}
		for(int j=i;j<=n;j++)
		{
			for(int q=i;q<j;q++)
			{
				if(b[q]==a[j]&&!f[q]&&!f[j])
				{
					for(int p=q;p<j;p++)
					{
						f[p]=1;
					}
				}
			}
			b[j]=a[j];
		}
		for(int j=i;j<=n;j++)
		{
			if(!f[j])
			{
				cnt[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<" ";
	}
	return 0;
}
