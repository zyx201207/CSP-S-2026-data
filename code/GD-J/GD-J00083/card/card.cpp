#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,a[N],b[M],ans[M],vis[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int k=0;k<n;k++)
	{
		int id=0;
		memset(vis,0,sizeof(vis));
		for(int i=1+k;i<=n;i++)
		{
			if(vis[a[i]]==0)
				b[++id]=a[i],vis[a[i]]=id;
			else
				b[min(vis[a[i]],id+1)]=a[i],id=min(vis[a[i]],id+1);
		}
		for(int i=1;i<=id;i++)
			ans[b[i]]++;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}
