#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p,w[5000],a[5000][5000],t[5000][5000],k[5000],cnt = 1,c2 = 1,x,y,ans,mk[5000];
void dfs(int l,int d,int cnt)
{
	if(d == y)
	{
		ans = max(ans,cnt+w[x]+w[y]);
		return;
	}
	for(int i=1;i<=k[l];i++)
	{
		if(mk[a[l][i]] == 0 && d != a[l][i])
		mk[a[l][i]]++;
		dfs(l,a[l][i],cnt+t[l][i]);
		cout<<cnt;
		mk[a[l][i]]--;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k[i];j++)
		{
			if(a[i][j] == a[l][d])
			{
				dfs(i,d,cnt+t[l][d]+t[i][d]);
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[c2];
		c2++;
		for(int j=1;j<=k[c2-1];j++)
		{
			cin>>a[i][cnt]>>t[i][cnt];
			cnt++;
		}
		cnt = 1;
	} 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k[i];j++)
		{
			cout<<a[i][j]<<" "<<t[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i=1;i<=p;i++)
	{
		cin>>x>>y;
		for(int j=1;j<=n;j++)
		{
			for(int s=1;s<=k[j];s++)
			{
				if(a[j][s] == x)
				{
					dfs(j,x,0);
				}
			}
		}
		cout<<ans<<endl;
		ans = 0;
	}
}
