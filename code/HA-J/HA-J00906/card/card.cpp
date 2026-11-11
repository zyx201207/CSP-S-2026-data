#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100005],book[100005],sum[100005],ans[100005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int j=1;j<=n;j++)
	{
		memset(sum,0,sizeof sum);
		memset(book,0,sizeof book);
		for(int i=j;i<=n;i++)
		{
			if(book[a[i]]==0)
			{
				book[a[i]]=1;
				sum[a[i]]++;
			}
			else
			{
				memset(sum,0,sizeof sum);
				memset(book,0,sizeof book);
				sum[a[i]]++;
				book[a[i]]=1;
				
			}
		}
		for(int i=1;i<=n;i++)
		{
			ans[i]+=sum[i];
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
}
