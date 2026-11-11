#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=510,maxm=5e5+10,inf=5e18;
int C,n,m,d,q,w[maxm],k[maxn],f[maxn][maxn];
struct node{
	int id,tt;
}tmp[maxm];
vector<int> a[maxn],t[maxn];
vector<int> p[maxm];
map<int,int> pos[maxn];
int cal(int i,int j,int q)
{
	int post1=pos[i][q],post2=pos[j][q];
	return t[i][post1]+t[j][post2];
}
bool cmp(node x,node y)
{
	return x.id<y.id;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>tmp[j].id>>tmp[j].tt;
			p[tmp[j].id].push_back(i);
		}
		sort(tmp+1,tmp+k[i]+1,cmp);
		a[i].push_back(0);t[i].push_back(0);
		for(int j=1;j<=k[i];j++)
			a[i].push_back(tmp[j].id),t[i].push_back(tmp[j].tt),pos[i][tmp[j].id]=j;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			f[i][j]=inf;
			if(i==j) f[i][j]=0;
		}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			int q=0;//record the position of the station
			for(int u=1;u<=k[i];u++)
			{
				while(a[j][q+1]<=a[i][u] && q<k[j]) q++;
				if(a[j][q]==a[i][u]) f[i][j]=cal(i,j,a[j][q]);
			}
		}
	}
	for(int p=1;p<=n;p++)
		for(int i=1;i<=n;i++)
		{
			if(i==p) continue;
			for(int j=1;j<=n;j++)
			{
				if(j==p || j==i) continue;
				if(f[i][p]>=inf || f[p][j]>=inf) continue;
				f[i][j]=min(f[i][j],f[i][p]+f[p][j]);
			}
		}
	for(int i=1;i<=q;i++)
	{
		int x,y;cin>>x>>y;
		int ans=1e18;
		for(auto pp:p[x])
			for(auto qq:p[y]) 
			{
				if(f[pp][qq]==inf) continue;
				int post1=pos[pp][x],post2=pos[qq][y];
				ans=min(ans,w[x]+w[y]+t[pp][post1]+t[qq][post2]+f[pp][qq]);
			}
		cout<<ans<<'\n';
	}
	return 0;
}
