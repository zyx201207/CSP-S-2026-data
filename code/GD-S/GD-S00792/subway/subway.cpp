#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5,N=505;
const long long INF=1e18;
inline int read()
{
	int res=0;
	char x=getchar();
	while(!isdigit(x))x=getchar();
	while(isdigit(x))
	{
		res=(res<<3)+(res<<1)+(x^48);
		x=getchar();
	}
	return res;
}
int c,n,m,d,q,k,x,y;
long long a[M],dis[N][N];
vector<pair<int,long long>> v[M];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++)a[i]=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)dis[i][j]=INF;
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=n;i++)
	{
		k=read();
		for(int j=1;j<=k;j++)
		{
			x=read();y=read();
			v[x].push_back(make_pair(i,y));
		}
	}
	for(int i=1;i<=m;i++)
		for(int j=0;j<v[i].size();j++)
			for(int k=j+1;k<v[i].size();k++)
				dis[v[i][k].first][v[i][j].first]=dis[v[i][j].first][v[i][k].first]=min(dis[v[i][j].first][v[i][k].first],v[i][j].second+v[i][k].second);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			if(i!=k)
				for(int j=1;j<=n;j++)
					if(i!=j&&k!=j)
						dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--)
	{
		x=read();y=read();
		long long res=INF;
		for(auto &i:v[x])
			for(auto &j:v[y])
				res=min(res,i.second+j.second+dis[i.first][j.first]);
		res+=a[x]+a[y];
		printf("%lld\n",res);
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
