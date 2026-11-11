#include<bits/stdc++.h>
using namespace std;
int n,m;
struct bucket
{
	int it[300005];
}v,null;
int a[500005];
int ans[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int j=1;j<=m;j++)
	{
		int res=0;
		v=null;
		for(int i=n;i>=1;i--)
		{
			ans[i]=0;
			if(v.it[a[i]]==0)
			{
				if(a[i]==j)	ans[i]=1;
				else ans[i]=ans[i+1];
				v.it[a[i]]=i;
			}
			else
			{
				ans[i]=ans[v.it[a[i]]+1];
				if(a[i]==j)	ans[i]=1;
			}	
			res+=ans[i];
		}
		cout<<res<<' ';
	}
}
