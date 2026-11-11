#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,x,y,w[1000007],a[50005],t[50005],k[505],ans;
struct str
{
	long long cou,ent;
}subw[1008][1008];
void dfs(long long stra,long long endd,long long step)
{
	if(stra==endd) 
	{
		ans=min(ans,step);
		return ;
	}
	for(long long i=1;i<=m;i++)
	{
		if(subw[stra][i].cou==1 && subw[i][stra].cou==1)
		{
			subw[stra][i].cou=0;
			subw[i][stra].cou=0;
			dfs(i,endd,step+subw[stra][i].ent+subw[i][stra].ent);
			subw[stra][i].cou=1;
			subw[i][stra].cou=1;
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++) 
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[j]>>t[j];
			if(j>1)
			{
				for(int l=j-1;l>=1;l--)
				{
					subw[a[l]][a[j]].cou=1;
					subw[a[j]][a[l]].cou=1;
					subw[a[l]][a[j]].ent=t[l];
					subw[a[j]][a[l]].ent=t[j];
				}
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		ans=142141238686412;
		cin>>x>>y;
		dfs(x,y,w[x]+w[y]);
		cout<<ans<<'\n';
	}
	return 0;
}
