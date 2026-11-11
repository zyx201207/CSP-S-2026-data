#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,ans=INT_MAX;
map<int,int>f[2000005];
int a[2000005],nm;
void work(int kk,int t)
{
	if(t==k)
	{
		int r=0;
		for(int i=1;i<=nm;i++)
		{
			for(int j=1;j<=nm;j++)
			{
				r=max(f[a[i]][a[j]],r);
			}
		}
		ans=min(ans,r);
		return;
	}
	if(kk>n)return;
	a[++nm]=kk;
	work(kk+1,t+1);
	nm--;
	work(kk+1,t);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				f[i][j]=1e8;
				if(i==j)f[i][j]=0;
			}
		}
		for(int i=1;i<n;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			f[x][y]=1;
			f[y][x]=1;
		}
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
			{
				if(i==k)continue;
				for(int j=1;j<=n;j++)
				{
					if(i==j||j==k)continue;
					f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
				}
			}
		}
		/*for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cout<<f[i][j]<<' ';
			}
			cout<<'\n';
		}*/
		ans=INT_MAX;
		work(1,0);
		printf("%d\n",ans);
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5

10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
