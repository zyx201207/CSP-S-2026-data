#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int n,m;
int a[N],b[N],c[N],ans[N],f[N],dp[N];//ccf chinese can fly
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i]=1;
	}
	for(int i=n;i>=1;i--)
	{
		if(b[a[i]]==0)b[a[i]]=i,c[i]=0;
		else if(b[a[i]]>0)c[i]=b[a[i]],b[a[i]]=i;
	}
	for(int i=n;i>=1;i--)
	{
		int l=i;
		while(l<=n)
		{
			if(c[l]!=0)f[l]-=1,f[c[l]+1]+=1,l=c[l]+1;
			else l=l+1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		f[i]+=f[i-1];
		dp[a[i]]+=f[i];
	}
	for(int i=1;i<=m;i++)
	{
		cout<<dp[i]<<" ";
	}
	return 0;
}