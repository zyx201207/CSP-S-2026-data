#include <bits/stdc++.h>
using namespace std;
int a[500005];
int ans[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			bool lans[300005];
			for(int j=1;j<=n;j++)
			{
				if(lans[j]==0)
				{
					ans[j]++;
					lans[j]=1;
				}
			}
		}
	for(int i=1;i<=m;i++)
		cout<<ans[i];
	return 0;
} 
