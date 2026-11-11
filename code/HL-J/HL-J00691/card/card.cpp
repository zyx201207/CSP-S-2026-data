#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+5]={},t[m+5]={},ans[m+1]={};
	vector<vector<int> >mp;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int j=1;j<=n;j++)
	{
		ans[j]=n;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=m;j++)
		{
			for(int k=i;k<=m;k++)
			{
				t[i]=0;
			}
			for(int k=i;k<=m;k++)
			{
				t[i]++;
			}
			if(t[j]!=1)
			{
				int k=j-1;
				while(a[k]!=a[j]&&k>=0)
				{
					ans[k--]--;	
				}
			}
			
		}
	}
	for(int i=1;i<=3;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}
