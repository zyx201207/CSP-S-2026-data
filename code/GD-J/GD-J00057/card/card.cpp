#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
//int ans[300010];
//bool vis[300010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==m)
	{
		for(int i=1;i<=m;i++)
		{
			cout<<n<<" ";
		}
		return 0;
	}
	if(m==1)
	{
		cout<<n;
		return 0;
	}
	return 0;
 } 
