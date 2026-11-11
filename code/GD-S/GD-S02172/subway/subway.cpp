#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
struct node
{
	int s;
	vector<int> e;
}a[N];
int c,n,m,d,q,line[510][N],ans,lo[N],sl[510][N],dl[N];
//vector<int> e[N];
bool v[N];
void dfs(int p,int y,int t,int pre)
{
	if(p==y)
	{
		ans=min(ans,t);
		return;
	}
	for(int k:a[p].e)
		for(int i=1;i<=lo[k];i++)
			if(!v[i])
			{
				v[i]=true;
				if(k==pre) dfs(i,y,t,pre);
				else dfs(i,y,t+sl[pre][i]+sl[k][i],k);
				v[i]=false; 
			}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)
		cin>>dl[i];
	for(int i=1,b,c,k;i<=m;i++)
	{
		cin>>lo[i];
		for(int j=1;j<=lo[i];j++)
		{
			cin>>b;
			cin>>sl[i][j];
			line[i][j]=b;
			a[b].s++,a[b].e.push_back(i);
		}
	}
	while(q--)
	{
		ans=1e9;
		int x,y;
		cin>>x>>y;
		dfs(x,y,0,a[x].e[1]);
		cout<<ans+dl[x]+dl[y]<<endl;
	}
	return 0;
}
