#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[100010];
int k[510];
long long ans;
map<int ,int >h[510];
long long f[510][510];
long long a[510][510];
vector<int> b[510];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		int x,y;
		for(int j=1;j<=k[i];j++)
		{
			cin>>x>>y;
			a[i][x]=y;
			b[i].push_back(x);
			h[i][x]=1;
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(i!=j)
			{
				for(int p=0;p<k[i];p++)
				{
					if(h[j][b[i][p]]) f[i][j]=f[j][i]=min(f[i][j],a[i][b[i][p]]+a[j][b[i][p]]);
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		f[i][i]=0;
		for(int j=1;j<=n;j++)
		{
			for(int p=1;p<=n;p++)
			{
				if(i!=j&&i!=p&&j!=p)
				{
					f[i][j]=min(f[i][j],f[i][p]+f[p][j]);
				}
			}
		}
	}
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		ans=w[l]+w[r];
		long long num=1e9;
		for(int i=1;i<=n;i++)
		{
			if(h[i][l])
			{
				for(int j=1;j<=n;j++)
				{
					if(h[j][r])
					{
						num=min(num,f[i][j]+a[i][l]+a[j][r]);
					}
				}
			}
		}
		cout<<ans+num<<'\n';
	}
}