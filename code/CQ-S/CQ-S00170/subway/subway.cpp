#include<bits/stdc++.h>
using namespace std;
const int N=553000;
long long ms[510][510],w[N],k[511],s,s1,vis[511];
vector<array<long long,2 > > e[510],g[N];
long long c,n,m,d,q;
struct xing{
	long long u,val;
};
bool operator < (xing a,xing b)
{
	return a.val>b.val;
 } 
priority_queue<xing> a1;
void dj(long long qd){
	ms[qd][qd]=0;
	a1.push({qd,0});
	memset(vis,0,sizeof(vis)); 
	while(!a1.empty()){
		long long u=a1.top().u;
		a1.pop();
		if(!vis[u])
		{
		vis[u]=1;
		for(auto p:e[u])
		{
			long long v=p[0],w=p[1];
			if(ms[qd][u]+w<ms[qd][v])
			{
				ms[qd][v]=ms[qd][u]+w;
				a1.push({v,ms[qd][v]});
			}
		}
	}
}
}
long long query(long long u,long long v)
{
	long long minn=1e16;
	for(auto p:g[u])
	{
		long long id=p[0];
		for(auto p1:g[v]){
			long long id1=p1[0];
			minn=min(minn,ms[id][id1]+p[1]+p1[1]);
		} 
	}
	return minn;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(ms,0x3f,sizeof(ms));
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
			cin>>s>>s1;
			g[s].push_back({i,s1});
		}	
	}
	for(int i=1;i<=m;i++){
		long long len=g[i].size();
		for(int j=0;j<len;j++)
		{
			for(int l=j+1;l<len;l++)
     		{
			    int u=g[i][j][0],v=g[i][l][0],w=g[i][j][1]+g[i][l][1];
			    e[u].push_back({v,w});
			    e[v].push_back({u,w});
		    }
		}
	}
	for(int i=1;i<=n;i++)
	{
		dj(i);
	}
	for(int i=1;i<=q;i++)
	{
		cin>>s>>s1;
		cout<<w[s]+w[s1]+query(s,s1)<<endl;
	}
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
