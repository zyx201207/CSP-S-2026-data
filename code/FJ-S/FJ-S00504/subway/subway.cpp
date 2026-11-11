#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[125255],l,r;
unordered_map<int,long long>ss[125255];
unordered_map<int,int>a[505];
bool b[505],can[125255][505];
void dfs(int x)
{
	if(ss[x].count(r))
		return;
	if(x==r)
	{
		ss[x][r]=0;
		return;
	}
	long long t=1e12;
	for(int i=1;i<=n;i++)
		if(!b[i]&&can[x][i])
		{
			b[i]=1;
			for(auto y:a[i])
			{
				dfs(y.first);
				if(ss[y.first].count(r))
					t=min(t,ss[y.first][r]+a[i][x]+y.second);
			}
			b[i]=0;
		}
	if(t!=1e12)
		ss[x][r]=t;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int s;
		cin>>s;
		for(int j=0;j<s;j++)
		{
			int aa,t;
			cin>>aa>>t;
			a[i][aa]=t;
			can[aa][i]=1;
		}
	}
	for(int p=1;p<=q;p++)
	{
		cin>>l>>r;
		if(!ss[l].count(r))
		{
			memset(b,0,sizeof b);
			dfs(l);
		}
		cout<<ss[l][r]+w[l]+w[r]<<"\n";
	}
	return 0;
}
