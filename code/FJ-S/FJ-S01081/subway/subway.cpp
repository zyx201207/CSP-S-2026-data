#include <bits/stdc++.h>
using namespace std;
int w[500010];
int a[510][50010];
int t[510][50010];
int b[510][50010];
int cn[50010];
int v[50010];
int k[510];
int ans=1e9;
int c,n,m,d,q;
bool fff=0;
void df(int x,int y,int cnt,int zz)
{
	
	v[x]=1;
	if(x==y)
	{
		cnt+=w[x];
		ans=min(cnt,ans);
	}
	
	for(int i=1;i<=cn[x];i++)
	{
	    for(int j=1;j<=k[a[x][i]];j++)
	    {
	    	if(v[b[a[x][i]][j]]==0)
	    	{
	    		
	    		df(b[a[x][i]][j],y,cnt+t[a[x][i]][b[a[x][i]][j]]+t[a[x][i]][x],a[x][i]);
	    		v[b[a[x][i]][j]]=0;
			}
		}
    }
	
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>b[i][j];
			cin>>t[i][b[i][j]];
			cn[b[i][j]]++;
			a[b[i][j]][cn[b[i][j]]]=i;
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		df(x,y,w[x],0);
		cout<<ans<<endl;
		ans=1e9;
		fff=0;
	}
	return 0;
}
