#include<bits/stdc++.h>
using namespace std;
const int N=1005;
//struct node{
//	int r,u,q;
//} a[10005];
//int edge[1005][1005];
int d[N][N];
int a[500005];
int e[20005][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,di,q;
	cin>>c>>n>>m>>di>>q;
//	if(c>=12&&c<=15)
//	{		
//		bool d1[20000][20000];
//		int T;
//		memset(d1,1,sizeof d1);
//		memset(e,0x3f,sizeof e);
//		for(int i=1;i<=m;i++){
//			scanf("%d",&a[i]);
//		}
//		for(int i=1;i<=n;i++)
//		{
//			int k;
//			cin>>k;
//			for(int j=1;j<=k;j++)
//			{
//				int station,need_time;
//				scanf("%d%d",&station,&need_time);
//				T=need_time;
//				for(int l=1;l<station;l++)  d1[station][l]=d1[l][station]=1;
//			}
//		}
//	//	for(int i=1;i<=m;i++)
//	//	{
//	//		for(int j=1;j<=m;j++)
//	//		{
//	//			cout<<d[i][j]<<" ";
//	//		}
//	//		cout<<endl;
//	//	}
//		bool f=1;
//		while(f)
//		{
//			f=0;
//			for(int i=1;i<=m;i++)
//			{
//				for(int j=1;j<m;j++)
//				{
//					for(int k=1;k<=m;k++)
//					{
//						if(d1[i][j]>d1[i][k]+d1[k][j])
//						{
//							f=1;
//							d1[i][j]=d1[j][i]=d1[i][k]+d1[k][j];
//						}
//					}
//				}
//			}
//		}
//		for(int i=1;i<=q;i++)
//		{
//			int st,en;
//			scanf("%d%d",&st,&en);
//			int ans=d1[st][en]*T+a[st]+a[en];
//			printf("%d\n",ans);
//		}
//		return 0;
//	}
	memset(d,0x3f,sizeof d);
	memset(e,0x3f,sizeof e);
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int station,need_time;
			scanf("%d%d",&station,&need_time);
			e[station][i]=need_time;
			for(int l=1;l<station;l++)  d[station][l]=d[l][station]=min(d[station][l],e[station][i]+e[l][i]);
		}
	}
//	for(int i=1;i<=m;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			cout<<d[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	bool f=1;
	while(f)
	{
		f=0;
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<m;j++)
			{
				for(int k=1;k<=m;k++)
				{
					if(d[i][j]>d[i][k]+d[k][j])
					{
						f=1;
						d[i][j]=d[j][i]=d[i][k]+d[k][j];
					}
				}
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int st,en;
		scanf("%d%d",&st,&en);
		int ans=d[st][en]+a[st]+a[en];
		printf("%d\n",ans);
	}
//	for(int i=1;i<=m;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			cout<<d[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	return 0;
}
/*
5 6 3
1 2 2
1 3 1
2 4 3
3 4 5
2 5 2
4 5 1
1 3
1 5
3 5
*/
