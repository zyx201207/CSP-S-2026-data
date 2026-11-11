#include<bits/stdc++.h>
using namespace std;
int n,m,ans[100000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int k[n+5],sum[m+5],maxn=0;
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		sum[k[i]]=i;
		maxn=max(sum[k[i]],maxn);
		for(int j=maxn;j<=n;j++)
		{
			if(k[j]==i)
			{
				ans[i]++;
			}	
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i];
	
		
	return 0;
}
