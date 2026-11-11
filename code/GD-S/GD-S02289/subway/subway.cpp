#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[505];
int k[500005];
bool a[505][500005];
int t[505][500005];
bool b[505][500005];
int minn=0x3f3f3f3f;
void find(int nowt,int nowz,int end,int sum)
{
	if(nowz==end)
	{
		minn=min(minn,sum);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i][nowz]==true)
		{
			if(b[i][nowz]==false)
			{
				b[i][nowz]==true;
				find(i,nowz,end,sum+t[nowt][nowz]+t[i][nowz]);
				b[i][nowz]==false;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(a[nowt][i]==true)
		{
			if(b[nowt][i]==false)
			{
				b[nowt][i]==true;
				find(nowt,i,end,sum+t[nowt][i]);
				b[nowt][i]==false;
			}
		}
	}
	return ;
}
int main()
{
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
			int u;
			cin>>u;
			a[i][u]=true;
			cin>>t[i][u];
		}
	}
	for(int i=1;i<=q;i++)
	{
		memset(b,false,sizeof(b));
		int x,y;
		cin>>x>>y;
		int ppp;
		for(int j=1;j<=n;j++)
		{
			b[j][x]=true;
			find(j,x,y,0);
			ppp=minn+w[x]+w[y]+t[j][x];
		}
		cout<<ppp<<endl;
	}
	return 0;
}
