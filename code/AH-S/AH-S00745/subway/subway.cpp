#include <bits/stdc++.h>
using namespace std;
struct node{
	int a,t;
};
int C,n,m,d,q;//n线路数,m地铁站数
int w[500005];
int mp1[1005][1005];
int st,ed,ans;
bool vis[1005];
vector <int> mp[1005];
void dfs(int x,int sum)
{
	cout<<x<<'\n';
	if (x==ed)
	{
		ans=min(ans,sum);
		return;
	}
	for (int i=0;i<mp[x].size();i++)
	{
		if (!vis[mp[x][i]])
		{
			vis[mp[x][i]]=1;
			dfs(mp[x][i],sum+mp1[x][mp[x][i]]);
			vis[mp[x][i]]=0;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>C>>n>>m>>d>>q;
	for (int i=1;i<=m;i++) cin>>w[i];
	for (int i=1;i<=m;i++) for (int j=1;j<=m;j++) mp1[i][j]=INT_MAX;
	for (int i=1;i<=n;i++)
	{
		int k;cin>>k;
		vector <node> tt;
		for (int j=1;j<=k;j++) 
		{
			node ss;cin>>ss.a>>ss.t;
			tt.push_back(ss);
		}
		for (int j=0;j<tt.size();j++) 
		{
			for (int k=j+1;k<tt.size();k++)
			{
				mp1[tt[j].a][tt[k].a]=min(tt[j].t+tt[k].t,mp1[tt[j].a][tt[k].a]);
				mp1[tt[k].a][tt[j].a]=min(tt[k].t+tt[j].t,mp1[tt[k].a][tt[j].a]);
			}
		}
	}
//	for (int i=1;i<=m;i++)
//	{
//		for (int j=1;j<=m;j++)
//			cout<<(mp1[i][j]==INT_MAX ? -1 : mp1[i][j])<<' ';
//		cout<<'\n';
//	}
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=m;j++)
			if (mp1[i][j]!=INT_MAX)
				mp[i].push_back(j);
//		cout<<mp[i].size()<<'\n';
	}
	while (q--)
	{
		cin>>st>>ed;
		ans=INT_MAX;
		vis[st]=1;
		dfs(st,0);
		vis[st]=0;
		ans+=w[st]+w[ed];
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
