#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5,N=505,D=25;
int c,n,m,d,q,p[M][D];
long long w[M],s[M][D],a[N][N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	memset(a,0x3f3f3f,sizeof(a));
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
		a[i][i]=0;
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x,t;
			cin>>x>>t;
			for(int l=1;l<=p[x][0];l++)
				a[i][p[x][l]]=a[p[x][l]][i]=min(a[i][p[x][l]],t+s[x][l]);
			p[x][0]++;
			p[x][p[x][0]]=i;
			s[x][p[x][0]]=t;
		}
	}
	for(int l=1;l<=n;l++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				a[i][j]=min(a[i][j],a[i][l]+a[l][j]);
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		long long ans=1e18;
		for(int i=1;i<=p[x][0];i++)
			for(int j=1;j<=p[y][0];j++)
				ans=min(ans,a[p[x][i]][p[y][j]]+s[x][i]+s[y][j]);
		cout<<w[x]+w[y]+ans<<'\n';
	}
	return 0;
}
