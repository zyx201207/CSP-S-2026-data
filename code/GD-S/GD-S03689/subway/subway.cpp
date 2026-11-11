#include<bits/stdc++.h>
using namespace std;
int q,n,m,st[505]={0},k,maap[1000][1000]={0},md[505],qx,zx,c,ad[1000][1000];;
long long minn=10086114514;
void dfs(int q,int d,int si)
{
	if(q==zx)
	{
		d+=ad[si][q];
		d+=md[q];
		if(minn>d)minn=d;
		return;
	}
	if(st[q]==1)return;
	st[q]=1;
	for(int i=1;i<=m;i++)
	{
		int nd=d;
		if(maap[q][i]!=0)
		{
			if(maap[q][i]==si)dfs(i,d,maap[q][i]);
			else if(maap[q][i]!=si)
			{
				nd+=ad[si][q];
				nd+=ad[maap[q][i]][q];
				dfs(i,nd,maap[q][i]);
			}
		}
	}
	st[q]=0;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>k>>q;
	for(int i=1;i<=m;i++)cin>>md[i];
	for(int i=1;i<=m;i++)st[i]=0;
	for(int i=1;i<=n;i++)
	{
		int kk;
		cin>>kk;
		for(int j=1;j<=kk;j++)
		{
			int qq,d,zz;
			cin>>zz>>d;
			ad[i][zz]=d;
			if(j>1)maap[qq][zz]=maap[zz][qq]=i;
			qq=zz;
		}
    }
	for(int i=1;i<=q;i++)
	{
		minn=10086114514;
		cin>>qx>>zx;
		dfs(qx,md[qx],0);
		cout<<minn<<endl;
	}
	return 0;
}
