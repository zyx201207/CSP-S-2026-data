#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,m;
int a[N],vis[N],cnt[N],b[N];
void out(int k,int x)
{
	for(int i=1;i<=k;i++)
	{
		if(a[i]==0||a[i]!=x) continue;
		for(int j=i;j<k;j++)
		{
			a[j]=0;
		}
		break; 
	}
}
signed main()
{
	freopen("card.in","r",stdin);	
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}		
	int k;
	for(int i=1;i<=n;i++)
	{
		k=i;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++) a[i]=b[i];
		for(int j=i;j<=n;j++)
		{
			vis[a[j]]++;
			if(vis[a[j]]>1)
			{
				k=j;
				out(k,a[j]);
			}
		}
		for(int j=i;j<=n;j++)
		{
			if(a[j]==0) continue;
			cnt[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<' ';
	}
	return 0;
}
