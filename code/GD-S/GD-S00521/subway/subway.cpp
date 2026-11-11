#include <bits/stdc++.h>
using namespace std;
const int N=510,M=5e5+10;
int c,n,m,d,q,p,x,y;
int num[N],r[M][25],cnt[M];
long long w[M],tt,t[M][25];
vector <int> a[N];
vector <long long> ti[N];
long long f[N][N],ans;
bool check;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for (int i=1;i<=m;i++) scanf("%d",&w[i]);
	for (int i=1;i<=n;i++) 
	{
		scanf("%d",&num[i]);
		for (int j=1;j<=num[i];j++)
		{
			scanf("%d%d",&p,&tt);
			a[i].push_back(p);
			ti[i].push_back(tt);
			cnt[p]++,r[p][cnt[p]]=i,t[p][cnt[p]]=tt;
		}
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			f[i][j]=1e18;
	for (int i=1;i<=n;i++)
	{
		//cout<<"铁路线"<<i<<endl;
		f[i][i]=0;
		for (int j=0;j<num[i];j++)
		{
			int p=a[i][j];
			//cout<<"站点"<<p<<endl; 
			for (int k=1;k<=cnt[p];k++)
			{
				f[i][r[p][k]]=min(f[i][r[p][k]],ti[i][j]+t[p][k]);
				//cout<<"可以达到路线"<<r[p][k]<<",费用为"<<ti[i][j]+t[p][k]<<endl;
			}
		}
	}
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while (q--)
	{
		scanf("%d%d",&x,&y);
		ans=1e18;
		for (int i=1;i<=cnt[x];i++)
			for (int j=1;j<=cnt[y];j++)
				ans=min(ans,t[x][i]+t[y][j]+f[r[x][i]][r[y][j]]);
		ans=ans+w[x]+w[y];
		cout<<ans<<endl;
	}
	return 0;
}
