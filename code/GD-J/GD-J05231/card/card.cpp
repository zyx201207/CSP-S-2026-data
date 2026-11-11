#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N];
int vis[M]={0};
int e[N],f[M]={0};
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=1;i--)
	{
		if(vis[a[i]]==0)
		{
			vis[a[i]]=i;
			e[i]=vis[a[i+1]];
		}
		else e[i]=vis[a[i]];
	}
	for(int i=1;i<=n;i++)f[i]=1;
	for(int i=1;i<=n;i++)
	{
		f[e[i]]+=f[i];
	}
	for(int i=1;i<=m;i++)
	{
		cout<<f[vis[i]]<<" ";
	}
	return 0;
}
