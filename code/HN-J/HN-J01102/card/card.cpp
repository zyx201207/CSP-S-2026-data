#include<bits/stdc++.h>
#define intn long long
using namespace std;
int last[500010];
int have[300010];
int a[500010];
int c[500010];
int ans[300010];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=n;i>=1;i--)
	{
		if(!have[a[i]])
		{
			have[a[i]]=i;
			last[i]=-1;
		}
		else
		{
			last[i]=have[a[i]];
		}
	}
	for(int i=1;i<=n;i++)
	{
		c[i]+=c[i-1];
		ans[a[i]]+=c[i]+i;
		if(last[i]!=-1)
		{
			c[i+1]-=c[i]+i;
			c[last[i]+1]+=c[i]+i;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	} 
}
