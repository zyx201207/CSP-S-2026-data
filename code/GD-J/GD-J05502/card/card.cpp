#include<bits/stdc++.h>
using namespace std;
struct node
{
	int l,r,t;
}st[500005];
int n,m,a[500005],vis[500005],l[500005],r[500005],sum[500005],ans[500005],to[500005];
int main()
{
	freopen("card2.in","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=n;i>=1;i--)
	{
		if(vis[a[i]]==0)
		{
			vis[a[i]]=i;
			to[i]=to[i+1];
			sum[to[i+1]]++;
		}
		else
		{
			sum[to[vis[a[i]]]]++;
			to[i]=to[vis[a[i]]];
		}
	}
	for(int i=1;i>=n;i--)
	return 0;
}
