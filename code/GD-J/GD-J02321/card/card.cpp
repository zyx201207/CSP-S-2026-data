#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
int last[300005];
int nex[500005];
int ans[300005];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;a[0]=-1e9;bool f=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];if(a[i-1]>a[i])f=0;
		last[a[i]]=i;
	}
	for(int i=1;i<=n;i++)nex[i]=last[a[i]];
	if(f)
	{
		for(int i=1;i<=m;i++)cout<<last[i]<<" ";
		return 0; 
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			ans[a[j]]++;
			while(nex[j]!=0 && nex[j]!=j)j=nex[j];
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
