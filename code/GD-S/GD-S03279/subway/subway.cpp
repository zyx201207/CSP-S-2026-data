#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,w[500001],a[500001],t[500001],aans;
bool p[500001];
vector<int>to[500001];
vector<int>cost[500001];
void find(int x,int y,int my)
{
	p[x]=1;
	if(x==y)
	{
		aans=min(aans,my);
		return;
	}
	for(int j=0;j<to[x].size();j++)
	{
		if(!p[to[x][j]])
		{
			find(to[x][j],y,my+cost[x][j]);
			p[to[x][j]]=0;
		}
	}
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
			cin>>a[j]>>t[j];
		for(int j=2;j<=k;j++)
		for(int l=1;l<j;l++)
		{
			to[a[j]].push_back(a[l]);
			to[a[l]].push_back(a[j]);
			cost[a[j]].push_back(t[j]+t[l]);
			cost[a[l]].push_back(t[j]+t[l]);
		}
	}
	for(int i=1;i<=q;i++)
	{
		aans=INT_MAX;
		memset(p,0,sizeof(p));
		int x,y;
		cin>>x>>y;
		find(x,y,0);
		cout<<w[x]+aans+w[y]<<endl;
	}
	return 0;
}
