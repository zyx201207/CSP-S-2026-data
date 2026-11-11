#include <bits/stdc++.h>

using namespace std;
int c,n,m,d,q,w[500005],oppp[505],a[505][505],t[505][505],ans,e[500005],book[500005],las[505][505];
int op=-1;
vector<vector<pair<int,int>>> G(500005);
void dij(int x,int y);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>oppp[i];
		int ti=0,lst=0;
		for(int j=1;j<=oppp[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			if(j!=1)
			{
				G[lst].push_back({a[i][j],i});
				G[a[i][j]].push_back({lst,i});
			}
			lst=a[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		for(int j=1;j<=m;j++)
		{
			e[j]=INT_MAX;
			book[j]=0;
		}
		op=-1;
		int x,y;
		cin>>x>>y;
		e[x]=0;
		dij(x,y);
		cout<<w[x]+w[y]+e[y]<<'\n';
	}
	return 0;
}
void dij(int x,int y)
{
	int k=op;
	if(book[x]==0)
	{
		book[x]++;
		for(auto i:G[x])
		{
			int prev=i.first,bh=i.second;
			int hj=0,jh=0;
			for(int mj=1;mj<=oppp[bh];mj++)
			{
				if(a[bh][mj]==x){hj=mj;}
			}
			for(int mj=1;mj<=oppp[op];mj++)
			{
				if(a[op][mj]==x){jh=mj;}
			}
			if(bh!=op){e[prev]=min(e[prev],e[x]+t[bh][hj]+t[op][jh]);if(op==-1){e[prev]=min(e[prev],e[x]+t[bh][hj]);}}
			else {e[prev]=min(e[prev],e[x]);}
			op=bh;
			if(prev==y)
			{
				long long jklo=0;
				for(int mj=1;mj<=oppp[bh];mj++)
				{
					if(a[bh][prev]==x){jklo=mj;}
				}
				e[prev]+=t[bh][jklo];
			}
			dij(prev,y);
			op=k;
		}
	}
	return ;
}
