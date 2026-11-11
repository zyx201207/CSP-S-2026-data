#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,n,m,d,q,w[500005],sub[505][20005],minn=INT_MAX,l,r;
bool bus[20005][505],mp[200005];
void dfs(int where,int time)
{
	if(mp[where])	return;
	if(where==r)
	{
		minn=min(minn,time+w[r]);
		return;
	}
	mp[where]=1;
	for(int i=1;i<=n;i++)
	{
		if(bus[where][i])
		{
			for(int j=1;j<=m;j++)
			{
				if(sub[i][j]!=0)
				{
					dfs(j,time+sub[i][j]+sub[i][i]);
				}
			}
		}
	}
	mp[where]=0;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)	cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int v,t;
			cin>>v>>t;
			bus[v][i]=1;
			sub[i][v]=t;
		}
	}
	while(q--)
	{
		cin>>l>>r;
		dfs(l,w[l]);
		cout<<minn<<"\n";
	}
	return 0;
}
/*啥题目，我真求你了$_$
  害得我都没时间写游记了^_^*/ 
