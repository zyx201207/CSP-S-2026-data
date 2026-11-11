#include<bits/stdc++.h>
using namespace std;
long long ans=0;
const int MAXM=500010;
int c,n,m,d,q;
int w[MAXM],xx,xr,yr;
/*struct Node
{
	int v,pre;
};
vector < Node> dian[MAXM];
void add_edg(int x,int y,int t)
{
	dian[x].push_back(Node{y,t});
	return ;
}
int bfs(int qq,int pp)
{
	queue < int> e;
	e.push(qq);
	while (!e.empty())
	{
		int ne=e.front();
		
	}
}*/
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)
	{
		cin>>w[i];
		ans+=w[i];
	}
	/*for (int i=1;i<=n;i++)
	{
		cin>>xx;
		int a=0,tt=0;
		for (int j=1;j<=2*xx;j++)
		{
			cin>>a;
			cin>>tt;
			add_edg(a,i,tt);
		}
	}
	for (int i=0;i<q;i++)
	{
		cin>>xr>>yr;
		cout<<bfs(xr,yr)+w[xr]+w[yr];
	}*/
	cout<<ans<<"\n";
	return 0;
}
