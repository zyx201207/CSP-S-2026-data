#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
struct node
{
	int to,w,num;
}
int c,n,m,d,q,w[N],a[505][50005],t[505][50005],ans,k[N];
vector<node> vts[N];
void dfs(int s,int t,int sum)
{
	if(s==t) ans=max(ans,sum);
	for(int i=0;i<vts[s].size();i++)
	{
		int v=vts[s][i].to,l=vts[s][i].w,num=vts[s][i].num;
		dfs(v,t,sum+t[i][num]+t[i][num-1]);
	}
}
int main()
{
	//while(1) rp++;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
		for(int j=2;j<=k[i];j++)
		{
			vts[a[i][j-1]].push_back(a[i][j],i,j);
		}
	}
	while(q--)
	{
		ans=0;
		int x,y;
		cin>>x>>y;dfs(x,y);
		cout<<w[x]+w[y]+ans<<endl;
	}
	return 0;
}
