#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

const int N=1e6+5;
int a[N],vis[N],t[N];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	int f=0;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(a[i]<a[i-1]) f=1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int f=j;
			for(int k=i;k<j;k++)
			{
				if(a[k]==a[j] && vis[k]==0)
				{
					f=k;
					break;
				}
			}
			for(int k=f;k<j;k++) vis[k]=1;
		}
		for(int j=i;j<=n;j++)
		{
			if(vis[j]==0) t[a[j]]++;
			vis[j]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<t[i]<<' ';
	}
	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/
//24
