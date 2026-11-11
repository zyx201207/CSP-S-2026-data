#include<bits/stdc++.h>
#define int long long
using namespace std;
const int my_inf=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q;
int w[500010],K;
int t[500010][25],a[500010][25],len[500010]; //da xiao,xian bian hao,xian chang du
int ne[510][510];
int dp[510][510],minn=my_inf;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			ne[i][j]=my_inf;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	int my_temp,my_temp1;
	for(int i=1;i<=n;i++)
	{
		cin>>K;
		for(int j=1;j<=K;j++)
		{
			cin>>my_temp>>my_temp1;
			len[my_temp]++;
			a[my_temp][len[my_temp]]=i;
			t[my_temp][len[my_temp]]=my_temp1;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=len[i];j++)
		{
			for(int k=j+1;k<=len[i];k++)
			{
				ne[a[i][j]][a[i][k]]=min(ne[a[i][j]][a[i][k]],t[i][j]+t[i][k]);
				ne[a[i][k]][a[i][j]]=min(ne[a[i][k]][a[i][j]],t[i][j]+t[i][k]);
			}
		}	
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j) dp[i][j]=0;
			else dp[i][j]=ne[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				dp[j][k]=min(dp[j][k],dp[j][i]+dp[i][k]);
			}
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			cout<<dp[i][j]<<" ";
//		}
//		cout<<'\n';
//	}
	int x,y;
	while(q--)
	{
		cin>>x>>y;
		minn=my_inf;
		for(int i=1;i<=len[x];i++)
		{
			for(int j=1;j<=len[y];j++)
			{
				minn=min(minn,w[x]+w[y]+t[x][i]+t[y][j]+dp[a[x][i]][a[y][j]]);
			}
		}
		cout<<minn<<'\n';
	}
	return 0;
}
