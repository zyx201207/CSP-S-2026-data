#include<bits/stdc++.h>
using namespace std;
const long long INF=1e16;
long long c,n,m,q,d;
long long w[500005],dis[505][505],t[500005][22],a[500005][22],ans,ed[505][505],nm[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	cin>>w[i];
	for(int i=1;i<=n;i++)
	{	int k,a1,t1;
		cin>>k;
		for(int j=1;j<=k;j++)
		cin>>a1>>t1,nm[a1]++,a[a1][nm[a1]]=i,t[a1][nm[a1]]=t1;
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	if(i!=j)ed[i][j]=dis[i][j]=INF;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<nm[i];j++)
		{
			for(int k=j+1;k<=nm[i];k++)
			{
				int x=a[i][j],y=a[i][k];
				if(ed[x][y]>t[i][j]+t[i][k])
				ed[x][y]=ed[y][x]=t[i][j]+t[i][k];
			}
		}
	}
	for(int k=n;k>=1;k--)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		dis[i][j]=min(dis[i][j],dis[i][k]+ed[k][j]);
	}
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		dis[i][j]=min(dis[i][j],dis[i][k]+ed[k][j]);
	}
	while(q--){
		int xr,yr;
		cin>>xr>>yr;
		ans=INF;long long sum=0;
		for(int i=1;i<=nm[xr];i++)
		for(int j=1;j<=nm[yr];j++)
		{sum=t[xr][i]+t[yr][j]+dis[a[xr][i]][a[yr][j]];
		if(sum<ans)ans=sum;
		}
		ans+=w[xr]+w[yr];
		cout<<ans<<endl;
	}
	return 0;
}
