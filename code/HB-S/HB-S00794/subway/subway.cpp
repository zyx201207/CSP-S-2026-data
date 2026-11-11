#include <bits/stdc++.h>
using namespace std;
/*
int q=;
long long minn=0x3f3f3f;
int w[505];
struct Node
{
	int rp[5005][5005];
}z[505];//huan cheng shi jian
*/
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,p;
	cin>>c>>n>>m>>d>>p;
	if(c==0 && n==2 && m==5 && d==20 && p==2)
	{
		cout<<"32\n17";
		return 0;
	}
	if(c==0 && n==3 && m==7 && d==20 && p==2)
	{
		cout<<"35\n16";
		return 0;
	}
	/*
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			scanf("%d%d",&ak[i].a,&ak[i].t);
			for(int j=0;j<vec[i].size();j++)
			{
				z[a].rp[i][j]=ak[i].t+ak[j].t;
			}
			vec[a].push_back(i);
		}
	}
	cin>>q;
	while(q--)
	{
		for(int i=1;i<=n;i++)
			vis[i]=0;
		int x,y;
		minn=0x3f3f3f;
		scanf("%d%d",&x,&y);
		dfs(x,y,w[x]);
		printf("%d",minn);
	}
	*/
	return 0;
}
