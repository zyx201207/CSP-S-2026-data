#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=505;
const int M=5e5+5;
int c,n,m,d,q;
int w[M];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	vector <pair<int,int> > v[m+1];
	for(int i=1;i<=n;i++){
		int k;
		scanf("%lld",&k);
		int a[k+1],t[k+1];
		for(int j=1;j<=k;j++){
			
			scanf("%lld%lld",&a[j],&t[j]);
			for(int p=1;p<=j;p++)
			{
				if(p==j) continue;
				int z=t[j]+t[p];
				v[a[j]].push_back({a[p],z});
				v[a[p]].push_back({a[j],z});
			}
		}
	}
	int dis[m+1];
	while(q--)
	{
		int x,y;
		scanf("%lld%lld",&x,&y);
		memset(dis,127,sizeof dis);
		dis[x]=0;
		bool vis[m+1];
		queue <int> q;
		vis[x]=1;
		q.push(x);
		while(!q.empty())
		{
			int k=q.front();
			q.pop();
			vis[k]=0;
			for(int i=0;i<(int)v[k].size();i++)
			{
				int u=v[k][i].first;
				int z=v[k][i].second;
				if(dis[u]>dis[k]+z)
				{
					dis[u]=dis[k]+z;
					if(!vis[u])
					{
						vis[u]=1;
						q.push(u);
					}
				}
			}
		}
		int ans=dis[y]+w[x]+w[y];
		printf("%lld\n",ans);
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
