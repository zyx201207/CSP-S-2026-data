#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int x,y;
}b[505][100005];
int n,m,d,q,l,r,mn,w[500005],k[500005],t[505][100005],vis[505],f[505];
vector <node> a[505];
vector <node> c[500005];
void dfs(int p,int s){
	if(s>=mn) return;
	if(f[p] && s!=0)
	{
		mn=min(mn,s+t[p][r]+w[r]);
		return;
	}
	if(s==0)
	{
		for(int i=0; i<c[p].size(); i++)
			if(!vis[c[p][i].x])
			{
				vis[c[p][i].x]=1;
				dfs(c[p][i].x,c[p][i].y+w[p]);
				vis[c[p][i].x]=0;
			}
		return;
	}
	for(int i=0; i<a[p].size(); i++)
		if(!vis[a[p][i].x])
		{
			vis[a[p][i].x]=1;
			dfs(a[p][i].x,s+a[p][i].y);
			vis[a[p][i].x]=0;
		}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>n>>m>>d>>q;
	for(int i=1; i<=m; i++)
		cin>>w[i];
	for(int i=1; i<=n; i++)
	{
		cin>>k[i];
		for(int j=1; j<=k[i]; j++)
		{
			cin>>b[i][j].x>>b[i][j].y;
			t[i][b[i][j].x]=b[i][j].y;
			c[b[i][j].x].push_back({i,b[i][j].y});
		}
	}
	for(int i=1; i<=n; i++)
		for(int j=1; j<=k[i]; j++)
			for(int ii=0; ii<c[b[i][j].x].size(); ii++)
			{
				if(i==c[b[i][j].x][ii].x) continue;
				a[i].push_back({c[b[i][j].x][ii].x,b[i][j].y+c[b[i][j].x][ii].y});
				a[c[b[i][j].x][ii].x].push_back({i,b[i][j].y+c[b[i][j].x][ii].y});
			}
	while(q--)
	{
		mn=1e18;
		cin>>l>>r;
		for(int i=0; i<c[r].size(); i++)
			f[c[r][i].x]=1;
		dfs(l,0);
		for(int i=0; i<c[r].size(); i++)
			f[c[r][i].x]=0;
		cout<<mn<<"\n";
	}
	return 0;
}
