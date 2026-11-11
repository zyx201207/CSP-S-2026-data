#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	int a[500005];
	int b[500005]={0};
	cin>>n>>m;
	int sum[500005]={0};
	for(int i=1;i<=n;i++)
	cin>>a[i];
	if(n!=m)
	{
		for(int i=1;i<=n;i++)//ju shu
		{
			memset(b,0,sizeof(b));
			int t=2;
			for(int j=i+1;j<=n;j++)// pai
			{
				b[1]=a[i];
				for(int k=1;k<=t;k++)
				{
					if(a[j]==b[k])
					{	
						for(int p=t-1;p>=k;p--)
						b[p]=0;
						t=k+1;
					}
					else
					{
						b[t]=a[j];
						t++;
					}
				}
			}
			sum[b[t]]++;
		}
		for(int i=1;i<=m;i++)
		cout<<sum[i]<<" ";
	}
	else
	{
		for(int i=m;i>=1;i--)
		cout<<i<<" ";
	}
	return 0;
}
