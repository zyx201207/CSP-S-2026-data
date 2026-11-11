#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500001],a[501][50001],t[501][50001],mn;
struct node
{
	int pos,way;
};
vector<node>g[500001];
void dfs(int now,int goal,int road,long long step)
{
	if(step>=mn) return;
	if(now==goal)
	{
		mn=step;
		return;	
	}
	for(int i=0;i<g[now].size();i++)
	{
		int pos=g[now][i].pos,way=g[now][i].way;
		if(!road||(road==way))
		{
			if(!road) step+=t[way][now]; 
			dfs(a[way][pos],goal,way,step+t[way][pos]);
		}
		else
			dfs(a[way][pos],goal,way,step+t[way][now]+t[way][pos]);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++) cin>>a[i][j]>>t[i][j];
		for(int j=1;j<k;j++)
		{
			for(int p=j+1;p<=k;p++)
			{
				g[a[i][j]].push_back((node){p,i});
			}
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		mn=1e18;
		dfs(x,y,0,0);
		cout<<w[x]+w[y]+mn<<endl;
	}
	return 0;
}
