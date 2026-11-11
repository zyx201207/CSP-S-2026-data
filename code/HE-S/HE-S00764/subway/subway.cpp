#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,qd,zd,w[500005],k[505],a[200005][505],t[200005][505],mx;
bool vis[500005];
vector<long long>g[500005];
struct Node{
	int step;
	int nx;
};
vector<int> dfs(int qd)
{
	vector<int>lj;
	vis[qd]=1;
	int sz=g[qd].size();
	for(int i=0;i<sz;i++)
	{
		int u=g[qd][i];
		if(!vis[u])	{
			if(u==zd)   
			{
				return lj;
			}
			else
			{
			lj.push_back(u);
			vis[u]=1;
			dfs(u);
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
		int k;
		cin>>k;
		mx=max(mx,k);
		for(int j=1;j<=k;j++)
	    {
			cin>>a[i][j]>>t[i][j];
		}
		for(int j=1;j<=k;j++)
		{
			for(int w=1;w<=k;w++)
			{
				if(w!=j)
					g[a[i][j]].push_back(a[i][w]);
			}
		} 
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<g[i].size();j++)
			cout<<g[i][j]<<" ";
			cout<<endl;
	}
	for(int i=1;i<=q;i++)	
	{
	cin>>qd>>zd;
	long long ans=w[qd]+w[zd];
	long long oldd=qd;
	vector<int>pos=dfs(qd);
	pos.push_back(zd);
	for(int i=0;i<pos.size();i++){
		ans+=t[oldd][oldd]+t[oldd][pos[i]];
	//	cout<<oldd<<" "<<t[oldd][oldd]<<" "<<t[oldd][pos[i]]<<endl;
		oldd=pos[i];
	}
	cout<<ans<<endl;
}
return 0;
}
