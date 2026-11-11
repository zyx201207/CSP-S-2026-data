#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;//point,lines,stations,nums,ques
int doortoterm[50009];
bool vis[50009];
int termtotrain[509][50009];//[lines][stations]
int minn;
void dfs(int sta,int fin,int time)
{
	if(sta==fin)
	{
		minn=min(minn,time);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(termtotrain[i][sta]==0) continue;
		for(int j=1;j<=m;j++)
		{
			if(termtotrain[i][j]==0||vis[j]) continue;
			vis[j]=1;
			time+=termtotrain[i][sta]+termtotrain[i][j];
			dfs(j,fin,time);
			time-=termtotrain[i][sta]+termtotrain[i][j];
			vis[j]=0;
		}
	}
}
int bfs(int start,int finish)
{
	minn=2e9;
	memset(vis,0,sizeof(vis));
	vis[start]=1;
	for(int i=1;i<=n;i++)
	{
		if(termtotrain[i][start]!=-1) dfs(start,finish,0);
	}
	return minn;
}
void solve()
{
	int start,finish;
	cin>>start>>finish;
	cout<<bfs(start,finish)<<' ';
}
int main()
{
	freopen("subway.in","r",stdout);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	//for(int i=0;i<=n;i++) for(int j=0;j<=m;j++) termtotrain[i][j]=-1;
	//memset(termtotrain,-1,sizeof(termtotrain));
	for(int i=1;i<=m;i++)
	{
		cin>>doortoterm[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;i++)
		{
			int x,t;
			cin>>x>>t;
			termtotrain[i][x]=t;
		}
	}
	for(int i=1;i<=q;i++) solve();
	return 0;
}

