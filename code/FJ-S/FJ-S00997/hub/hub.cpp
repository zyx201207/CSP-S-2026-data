#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=1e6+5;
int n,T,c,fa[N],tmp[N],dis[200][200],d[200][200],k,ans;
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void dfs(int step)
{
	if(step>n)
	{
		for(int i=1;i<=n;i++)fa[i]=i;
		vector<int>v;
		for(int i=1;i<=n;i++)if(tmp[i])v.push_back(i);
		if(v.size()!=k)return;
		for(int i:v)
			for(int j:v)
				if(i!=j&&d[i][j])
				{
					int x=find(i),y=find(j);
					if(x==y)continue;
					fa[x]=y;
				}
		int cnt=0;
		for(int i:v)if(find(i)==i)cnt++;
		if(cnt!=2)return;
		int res=0;
		for(int i=1;i<=n;i++)
		{
			int t=1e9;
			for(int j:v)
				t=min(t,dis[i][j]);
			res=max(res,t);
		}
		ans=min(ans,res);
		return;
	}
	tmp[step]=0;
	dfs(step+1);
	tmp[step]=1;
	dfs(step+1);
	return;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>k;
		memset(dis,0x3f,sizeof dis);
		for(int i=1;i<=n;i++)dis[i][i]=0;
		for(int i=1;i<=n-1;i++)
		{
			int a,b;
			cin>>a>>b;
			d[a][b]=d[b][a]=1;
			dis[a][b]=dis[b][a]=1;
		}
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					if(i!=j&&j!=k&&i!=k)
						dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		ans=1e9;
		dfs(1);
		cout<<ans<<'\n';
		memset(d,0,sizeof d);
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
