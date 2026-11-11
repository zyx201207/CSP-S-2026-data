#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010],tot[300010];
int vis[300010];
int q[500010],t;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++)
		{
			if(vis[a[j]])
			{
				while(t)
					if(q[t]!=a[j])
					{
						vis[q[t]]=0;
						t--;
					}
					else break;
				t--;
			}
			vis[a[j]]=1;
			q[++t]=a[j];
		}
		while(t>=1) tot[q[t--]]++;
	}
	for(int i=1;i<=m;i++)
		cout<<tot[i]<<" ";
	return 0;
}
