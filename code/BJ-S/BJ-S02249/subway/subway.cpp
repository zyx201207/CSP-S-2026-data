#include <bits/stdc++.h>
using namespace std;
const int INF=2e9+7;
const int Nmax=5e5+7;
int c,n,m,d,q,ans=0;
int sd,fd;
priority_queue<pair<int,int>> pq;
struct Nide{
	int t1,t2,go;
}a[Nmax];
struct Node{
	int v,w;
};
vector<Node> e[Nmax];
int mp[Nmax];
int dx[4]={-1,1};
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].t1;
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[k].go>>a[k].t2;
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>sd>>fd;
		for(int j=sd;j<=fd;j++)
		{
			ans+=a[j].t1+a[j].t2;
		}
		// mp[sd]=1;
		// dfs(sd,0);
		cout<<ans<<endl;
	}
	return 0;
}