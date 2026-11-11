#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100005],ans[1000005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int k=1;k<=n;k++)
	{
		int b[n],len=0;
		for(int i=k;i<=n;i++)
		{
			int h=lower_bound(b+1,b+n+1,a[i])-b;
			if(b[h]==a[i])
			{
				len=h+1;
				for(int j=h+1;j<=n;j++)
				{
					b[i]=0;
				}
			}
			else
			{
				b[len]=a[i];
				len++;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(b[i]!=0)
			{
				ans[b[i]]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
}
