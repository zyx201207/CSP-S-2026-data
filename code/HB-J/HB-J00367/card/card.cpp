#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,last[5005],ans[5005],a[5005],pre[5005];
bool p[5005];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		last[i]=pre[a[i]];
		pre[a[i]]=i;
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=m;i++)p[i]=0,last[i]=n+1;
		for(int i=k;i<=n;i++)
		{
			last[i]=pre[a[i]];
			p[a[i]]=1;
			for(int j=1;j<=m;j++)
			{
				if(i==j)continue;
				if(pre[a[i]]<last[pre[j]])p[j]=0,last[pre[j]]=0;
				//if(p[j]==1)ans[j]++;
			}
			pre[a[i]]=i;
		}
		for(int i=1;i<=m;i++)if(p[i]==1)ans[i]++;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
4 3
1 2 1 3
*/
