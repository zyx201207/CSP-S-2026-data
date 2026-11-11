#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,d,q,x,y,ans=1000000002;
ll w[500005],a[5005][5005],k[505],dp[5005][5005],b[5005][5005];
void dfs(int s,ll d)
{
	if(s==y)
	{
		ans=min(ans,d);
		return;
	}
	if(d>ans)
	{
		return;
	}
	if(s>m)
	{
		
		for(int i=1;i<=m;i++)
		{
			if(a[s][i]&&!b[s][i])
			{
				b[s][i]=1;
				b[i][s]=1;
				dfs(i,a[s][i]+d);
				b[s][i]=0;
				b[i][s]=0;
			}
		}
	}
	else
	{
		
		for(int i=1;i<=n;i++)
		{
			if(a[s][m+i])
			{
				b[m+i][s]=1;
				b[s][m+i]=1;
				dfs(m+i,a[s][m+i]);
				b[s][m+i]=0;
				b[m+i][s]=0;
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		int fr,to,l,r;
		if(k[i]==2)
		{
			cin>>fr>>to;
			cin>>l>>r;
			a[m+i][fr]=to+w[fr];
			a[fr][m+i]=to+w[fr];
			a[l][m+i]=r+w[l];
			a[m+i][l]=r+w[l];
			a[fr][l]=-1;
			a[l][fr]=-1;
		}else
		{
			cin>>fr>>to;
		}
	}
	while(q--)
	{
		cin>>x>>y;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[m+i][x])
			{
				b[x][m+i]=1;
				b[m+i][x]=1;
				dfs(m+i,a[x][m+i]);
				b[x][m+i]=0;
				b[m+i][x]=0;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

