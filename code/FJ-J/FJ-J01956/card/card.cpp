#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int paim[3000010];
int sz[3000010];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	int n,m;
	cin>>n>>m;
	int szs=0;
	for(int i=1;i<=n;i++)
	{
		cin>>paim[i];
	}
	int k=1;
	int nn=n;
	while(nn--)
	{
		k++;
		int bj=1;
		for(int i=k;i<=n;i++)
		{
			for(int j=1;j<i;j++)
			{
				if(paim[i]==paim[j])
				{
					bj=i;
				}
			}
		}
		for(int z=bj;z<=n;z++)
		{
			sz[paim[z]]++;
		}	
	}
	for(int j=1;j<=m;j++)
	{
		cout<<sz[j]<<" ";
	}
	return 0;
} 
