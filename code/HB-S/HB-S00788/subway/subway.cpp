#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int ti[505],a[25][25],t[25][25],r[505];//a[lu][zhan] ,t[zhanting][lu]
int book[505];
int ans=0x3f3f3f3f;
void dfs(int x,int e,int sum)
{
	if(x==e)
	{
		ans=min(ans,sum);
		return;
	}
	for(int i=1;i<=r[x];i++)
	{
		if(a[i][x]==0)continue;
		//x zhantin->i zhantai
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]==0 || book[j]==1)continue;
			book[j]=1;
			dfs(j,e,sum+t[j][i]+t[x][i]);
			book[j]=0;
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>ti[i];
	}
	int s;
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		
		for(int j=1;j<=k;j++)
		{
			cin>>s;
			int w;
			cin>>w;
			r[s]++;
			a[j][s]=1;//i lu->a[j]zhan 
			t[s][i]=w;// s zhanting->izhantai
		}
	}
	int e;
	for(int i=1;i<=q;i++)
	{
		memset(book,0,sizeof book);
		cin>>s>>e;
		ans=0x3f3f3f3f;
		book[s]=1;
		dfs(s,e,0);
		cout<<ans+ti[s]+ti[e];
	}
	
	return 0;
}
