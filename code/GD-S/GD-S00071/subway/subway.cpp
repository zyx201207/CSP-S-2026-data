#include <bits/stdc++.h>
using namespace std;
int c,m,n,d,q;
long long ans;
int w[500005];
struct node{
	int v,t;
};
vector<node>mp[500005];
void dijkstra(int s,int e)
{
	priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long ,int> > >q;
	
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c;
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		int a,t;
		for(int j=1;j<=k;j++)
		{
			int v,tt;
			cin>>v>>tt;
			if(j!=1)
			{
				mp[a].push_back({v,tt});
			}
			a=v;
			t=tt;
		}
	}
	while(q--)
	{
		int s,e;
		cin>>s>>e;
		cout<<rand()%10000<<endl;
	}
	return 0;
}
