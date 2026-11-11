#include<bits/stdc++.h>
using namespace std;
long long c,m,n,d,q,zd,minv=10000;
long long w[100005],k[1005],a[505][5005],t[505][5005],x[100005],y[100005];
long long v[5005][505],cnt[100005];
bool vis[505];
//w:口--->厅  time
//a i,j 第 i 条线路 经过de第 j 个地铁站
//t i,j 从j地铁站的厅--->第 i 条线路的台 需要的时间。
/*
	 0 2 5 20 2
 4 1 9 2 5
 3 1 5 2 7 4 6
 3 2 3 3 4 5 7
 1 3
 1 2*/
void dfs(long long xx,long long sum)
{
	if(sum>=minv)return;
	if(xx==zd)
	{
		//cout<<"Yeah"<<endl;
		minv=min(minv,sum+w[zd]);
		return;
	}
	//if(cnt[xx]==0)return;
	vis[xx]=1;
	for(long long i=1;i<=cnt[xx];i++)
	{
		long long xl=v[xx][i];
		for(int j=1;j<=k[xl];j++)
		{
			long long dtz=a[xl][j];
			if(vis[dtz]==1)continue;
			vis[dtz]=1;
			//cout<<xl<<" "<<xx<<" / "<<xl<<" "<<dtz<<"::"<<t[xl][xx]<<"|"<<t[xl][dtz]<<endl;
			dfs(dtz,sum+t[xl][xx]+t[xl][dtz]);
			vis[dtz]=0;
		}
	}
	//cout<<222<<endl;
	return;
}
int main(void)
{
	//subway
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
			cnt[a[i][j]]++;
			v[a[i][j]][cnt[a[i][j]]]=i;
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=q;i++)
	{
		zd=y[i];
		minv=1e15;
		for(int i=1;i<=505;i++)vis[i]=0;
		if(zd==x[i])
		{
			cout<<0<<endl;
		}
		else
		{
			dfs(x[i],w[x[i]]);
			cout<<minv<<endl;
		}
	}
	/*
	 0 3 7 20 2
 8 3 6 1 7 2 9
 3 1 4 2 5 5 100
 3 2 6 3 1 7 2
 4 3 2 5 100 4 6 6 7
 1 6
 2 3
	 */
	return 0;
}
