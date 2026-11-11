#include<bits/stdc++.h>
using namespace std;
struct station{
	int num;
	int val;
};
struct ch
{
	int yesno;
	int xuhao;
};
int c,n,m,d,q;
int a[600];
ch check[600][20099];
int bj[600];
vector<station>b[600];
int len[600];
int ans=INT_MAX;
int bing=0;
void dfs(int now,int to,int va)
{
	if(now==to) 
	{
		ans=min(ans,va);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(bj[i]==1) continue;
		if(check[i][now].yesno==1)
		{
			bj[i]=1;
			for(int j=0;j<len[i];j++)
			{
				if(b[i][j].num!=now)
				{
					dfs(b[i][j].num,to,va+b[i][j].val+b[i][check[i][now].xuhao].val);
				}
			}
			bj[i]=0;
		}
	}
}
signed main(){
//	cout<<1;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int j;
		cin>>j;
		len[i]=j;
		int cnt=0;
		for(int k=1;k<=j;k++)
		{
			int t1,t2;
			cin>>t1>>t2;
			b[i].push_back({t1,t2});
			check[i][t1]={1,cnt++};
		}
	}
	for(int t9=0;t9<q;t9++)
	{
		int start,end;
		cin>>start>>end;
		ans=INT_MAX;
		dfs(start,end,0);
		cout<<ans+a[start]+a[end]<<endl;
	}
}

