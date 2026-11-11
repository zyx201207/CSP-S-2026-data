#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int qwq[5000005];
vector<pair<int,int>> a[500005];
vector<int> b[500005];
long long val=0;
bool vis[500005][25];
long long dis[500005];
long long spfa()
{
	
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k*2;j++)
		{
			cin>>qwq[j];
			if(j%2==1&&j>1)
			{
				a[qwq[j]].push_back({i,qwq[j-2]});
				a[qwq[j-2]].push_back({i,qwq[j]});
				b[qwq[j]].push(i);
			} 
			else
				val=qwq[j];
		}
	}
	while(q--)
	{
		memset(vis,0,sizeof(vis));
		int x,y;
		cin>>x>>y;
		cout<<spfa();		
	}
	return 0; 
} 
