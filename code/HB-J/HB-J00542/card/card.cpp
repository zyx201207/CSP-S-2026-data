#include<bits/stdc++.h>
using namespace std;
int a[500001],t[500001],ans[300001],pos[500001],v[500001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	int n,m,rt=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		rt=0;memset(t,0,sizeof(t));
		memset(pos,0,sizeof(pos));memset(v,0,sizeof(v));
		for(int j=i;j<=n;j++)
		{
			int x=a[j];
			if(pos[x]==0)
			{
				rt++;
			    pos[x]=rt;t[rt]=x;
			}
			else
			{
				for(int k=pos[x];k<=rt;k++) 
				{
					t[k]=0;pos[t[k]]=0;
				}
				rt=pos[x];t[rt]=x;
				pos[x]=rt;
			}
		}
		for(int j=1;j<=rt;j++) 
		{
			v[t[j]]=1;
		}
		for(int j=1;j<=m;j++)
		{
			if(v[j]==1) ans[j]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
