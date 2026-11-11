#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[500009];
//vector<pair<long long,long long> >gg[509];
vector<pair<long long,long long> >mg[500009]; 
long long k[555];
vector<pair<long long,long long> >sg[509];
long long ll[505][505];
long long vis[505];
void kkru(int u)
{
	priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> > > kru;
	kru.push({0,u});
	memset(vis,0,sizeof(vis));
	while(!kru.empty())
	{
		auto h=kru.top();
		kru.pop();
//		cout<<u<<" "<<h.second<<"\n";
		vis[h.second]=1;
		for(auto kk:sg[h.second])
		{
			if(!vis[kk.first])
			kru.push({kk.second,kk.first});
//			vis[kk.first]=1;
			if(ll[u][h.second]>ll[u][kk.first]+kk.second)
			ll[u][h.second]=ll[u][kk.first]+kk.second;
			vis[kk.first]=1;
		}
		
	}
//	queue<long long> qq;
//	qq.push(u);
//	while(!qq.empty())
//	{
//		long long g=qq.front();
//		qq.pop();
//		for(auto kk:sg[g])
//		{
//			if(!vis[kk.first])
//			{
//				qq.push(kk.first);
//			}
//			else
//			{
//				if(ll[u][g]>ll[u][kk.first]+kk.second);
//				ll[u][g]=ll[u][kk.first]+kk.second;
//			}
//		}
//	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
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
			long long a,b;
			cin>>a>>b;
//			gg[i].push_back({a,b});
			mg[a].push_back({i,b});
		}
	}
	memset(ll,0x3f,sizeof(ll));
	for(int i=1;i<=m;i++)
	{
		for(auto tt:mg[i])
		{
			for(auto ttt:mg[i])
			{
				if(tt==ttt)
				{
					continue;
				}
				sg[tt.first].push_back({ttt.first,tt.second+ttt.second});
				sg[ttt.first].push_back({tt.first,tt.second+ttt.second});
				ll[tt.first][ttt.first]=tt.second+ttt.second;
				ll[ttt.first][tt.first]=tt.second+ttt.second;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		kkru(i);
		ll[i][i]=0;
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			cout<<ll[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	for(int i=1;i<=q;i++)
	{
		long long x,y;
		cin>>x>>y;
		long long ans=0x3f3f3f3f3f3f3f3f;
		long long now=0;
		for(auto tt:mg[x])
		{
			for(auto ttt:mg[y])
			{
				now=tt.second+ttt.second+ll[tt.first][ttt.first];
				ans=min(ans,now+w[x]+w[y]);
			}
		}
		cout<<ans<<"\n";
	}
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
