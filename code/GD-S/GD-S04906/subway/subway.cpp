#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int c,n,m,d,q;
int w[500005];
int t[505][25];
vector<int>sub[505];
int sub1[500005];
vector<pair<int,int>>gra[500005];
bool vis[500005];
int dfs(int s,int e,int last)
{
	if(s==e)
	{
		return t[last][s];
	}
	int kkl=1e9;
	//cout<<gra[s].size()<<' ';
	for(int i=0;i<gra[s].size();i++)
	{
		if(gra[s][i].second==last&&vis[gra[s][i].first]==0)
		{
			vis[gra[s][i].first]=1;
			kkl=min(kkl,dfs(gra[s][i].first,e,last));
		}
		else if(vis[gra[s][i].first]==0)
		{
			vis[gra[s][i].first]=1;
			kkl=min(kkl,dfs(gra[s][i].first,e,gra[s][i].second)+t[last][s]+t[gra[s][i].second][s]);
		}
		else continue;
	}
	return kkl;
}
int main(int argc, char** argv) {
	//auto start=clock();
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k,a,t1;
		cin>>k>>a>>t1;
		sub[i].push_back(a);
		sub1[a]=i;
		t[i][a]=t1;
		for(int j=2;j<=k;j++)
		{
			int a,t1;
			cin>>a>>t1;
			sub[i].push_back(a);
			sub1[a]=i;
			t[i][a]=t1;
			gra[a].push_back({sub[i][j-2],i});
			gra[sub[i][j-2]].push_back({a,i});
			//cout<<a<<"->"<<sub[i][j-2]<<":"<<i<<endl;
			//cout<<sub[i][j-2]<<"->"<<a<<":"<<i<<endl;
		}
	}
	while(q--)
	{
		memset(vis,0,sizeof(vis));
		int x,y,ans=0;
		cin>>x>>y;
		ans+=(w[x]+w[y]+t[sub1[x]][x]);
		ans+=dfs(x,y,sub1[x]);
		cout<<ans<<endl;
	}
	//auto end=clock();
	//cout<<end-start;
	return 0;
}
