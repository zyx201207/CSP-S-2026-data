#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],k[505],x[500005],y[500005],s[500005];
long long a[505][125255];
long long xi,yi;
long long minn=LLONG_MAX;
bool p[505][125255];
void dfs(int xx,int yy,int sum)
{
	if(a[xx][yi]!=0){minn=min(minn,sum+a[xx][yi]+w[yi]);return ;}
	for(int i=yy;i<=k[xx];i++)
	{
		if(a[i+1][x[i]]!=0&&p[i+1][x[i]]==0)
		{
			p[i][x[i]]=1;
			dfs(xx+1,i,sum+a[i][x[i]]+a[i+1][x[i]]);
		    p[i][x[i]]=0;
		}
		if(a[i-1][x[i]]!=0&&p[i-1][x[i]]==0)
		{
			p[i][x[i]]=1;
			dfs(xx+1,i,sum+a[i][x[i]]+a[i-1][x[i]]);
		    p[i][x[i]]=0;
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>x[j]>>y[j];
			a[i][x[j]]=y[j];
		}
	}
	while(q--)
	{
		cin>>xi>>yi;
		for(int i=1;i<=n;i++)
		{
			if(a[i][xi]!=0)
			{
				cout<<w[xi]+a[i][xi]+a[i][yi]+w[yi]<<"\n";
				break;
			}
		}
	}
	return 0;
}

