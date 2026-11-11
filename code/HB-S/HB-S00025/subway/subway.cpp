#include <bits/stdc++.h>
using namespace std;
const int N=5e4+5;
int c,n,m,d,q;
int xr,yr;
int w[N];
int a[505][N],t[505][N];
int book[505][N];
int ans[505];
int op[505];
int res;
vector<int> e[505];
void dfs(int u,int idnow,int ed,int now)
{
	book[u][idnow]=1;
	if(u==ed)
	{
		res=min(res,now);
		return ;
	}
	for(int i=0;i<(int)e[u].size();i+=2)
	{
		int idnext=e[u][i],v=e[u][i+1];
		if(idnext==idnow)
		{
			if(book[v][idnext]) continue;
			for(int j=1;j<=op[idnext];j++)
			{
				if(a[idnext][j]==v)
				{
					dfs(v,idnext,ed,now+t[idnext][j]);
					break;
				}
			}
		}
		else
		{
			if(book[u][idnext]) continue;
			for(int j=1;j<=op[idnext];j++)
			{
				if(a[idnext][j]==u)
				{
					dfs(u,idnext,ed,now+t[idnext][j]);
					break;
				}
			}
		}
	}
	return ;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)
	{
		cin>>op[i];
		for(int j=1;j<=op[i];j++)
		{
			scanf("%d%d",&a[i][j],&t[i][j]);
			if(j>=2)
			{
				e[a[i][j]].push_back(i);
				e[a[i][j]].push_back(a[i][j-1]);
				e[a[i][j-1]].push_back(i);
				e[a[i][j-1]].push_back(a[i][j]);
			}
		}
	}
	memset(ans,0x3f,sizeof ans);
	for(int i=1;i<=q;i++)
	{
		cin>>xr>>yr;
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=op[j];k++)
			{
				if(a[j][k]==xr)
				{
					memset(book,0,sizeof book);
					res=0x3f3f3f3f;
					dfs(xr,j,yr,t[j][k]);
					ans[i]=min(ans[i],res+w[xr]+w[yr]);
				}
			}
		}
	}
	for(int i=1;i<=q;i++) cout<<ans[i]<<"\n";
	return 0;
}
