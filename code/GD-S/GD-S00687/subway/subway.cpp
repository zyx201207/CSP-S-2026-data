#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505,M=5e5+5;
ll f[N][N],w[M];
int l[M];
vector<int> a[M],t[M];
struct type
{
	int v,w;
};
vector<type> h[M];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	memset(f,0x3f,sizeof(f));
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
		f[i][i]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>l[i];
		for(int j=1;j<=l[i];j++)
		{
			int u,w;
			cin>>u>>w;
			a[u].push_back(i);
			t[u].push_back(w);
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<a[i].size();j++)
		{
			int u=a[i][j],v;
			for(int k=0;k<a[i].size();k++)
			{
				v=a[i][k];
				f[u][v]=f[v][u]=min(f[u][v],t[i][j]+(ll)t[i][k]);
//				cout<<"kkkkkkkkkkkkkkkkkk\n";
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	}
//	cout<<"-----------------------\n";
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			cout<<f[i][j]<<" ";
//		}
//		cout<<"\n";
//	} 
//	cout<<"-----------------------\n";
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		ll ans=1e16;
		for(int i=0;i<a[x].size();i++)
		{
			int u=a[x][i],v;
			for(int j=0;j<a[y].size();j++)
			{
				v=a[y][j];
//				cout<<u<<" "<<v<<" "<<t[x][i]<<" "<<t[y][j]<<"\n";
				ans=min(ans,f[u][v]+t[x][i]+t[y][j]);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
