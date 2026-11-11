#include<bits/stdc++.h>
#define N 505 
#define M 140005 
#define K 500005 
#define D 25 
#define mod
#define MAXX 1000000000000000000
#define MINN -1000000000000000000
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

struct node{
	ll id,tim; 
};

struct nodeed{
	ll id,s; 
	bool operator < (const nodeed &r) const{
		return r.s<s; 
	}
};

ll c,n,m,d,qq; 
ll w[N]; 
ll cnt[M]; 
node t[M][D]; 
ll dis[N*2][N*2]; 
ll vis[N*2]; 
ll e[N*2][N*2]; 

void dijkstra(ll u)
{
	priority_queue<nodeed>q; 
	for(ll i=1;i<=n+n;i++)
	{
		dis[u][i]=MAXX; 
	}
	dis[u][u]=0; 
	q.push({u,0}); 
	while(q.size())
	{
		nodeed h=q.top(); 
		q.pop(); 
		ll ci=h.id; 
		if(vis[ci]) continue; 
		vis[ci]=1; 
		for(ll i=1;i<=n+n;i++)
		{
			if(e[ci][i]==MAXX)
			{
				continue; 
			}
			ll v=i; 
			ll ww=e[ci][v]; 
			if(dis[u][v]>ww+dis[u][ci])
			{
				dis[u][v]=ww+dis[u][ci]; 
				q.push({v,dis[u][v]}); 
			}
		}
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	freopen("subway5.in","r",stdin);
//	freopen("1.out","w",stdout);

	cin>>c>>n>>m>>d>>qq; 
//	cout<<qq<<"qq\n"; 
	for(ll i=1;i<=m;i++)
	{
		cin>>w[i]; 
	}
	for(ll i=1;i<=n;i++)
	{
		ll k; 
		cin>>k; 
		for(ll j=1;j<=k;j++)
		{
			ll a,tt; 
			cin>>a>>tt; 
			cnt[a]++; 
			t[a][cnt[a]].id=i; 
			t[a][cnt[a]].tim=tt; 
		}
	}
	for(ll i=1;i<=n+n;i++)
	{
		for(ll j=1;j<=n+n;j++)
		{
			e[i][j]=MAXX; 
		}
		e[i][i+n]=0; 
	} 
	for(ll id=1;id<=m;id++)
	{
		for(ll i=1;i<=cnt[id];i++)
		{
			ll x=t[id][i].id; 
			e[x][x+n]=0; 
			for(ll j=i+1;j<=cnt[id];j++)
			{
				ll y=t[id][j].id; 
				e[x][y]=min(e[x][y],t[id][i].tim+t[id][j].tim); 
				e[y][x]=min(e[y][x],t[id][i].tim+t[id][j].tim); 
			}
		}
	}
//	cout<<"---\n"; 
//	for(ll i=1;i<=n;i++)
//	{
//		for(ll j=1;j<=n+n;j++)
//		{
//			cout<<e[i][j]<<" "; 
//		}
//		cout<<"\n"; 
//	}
//	cout<<"---\n"; 
	for(ll i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis)); 
		dijkstra(i); 
	}
//	cout<<"---\n"; 
//	for(ll i=1;i<=n;i++)
//	{
//		for(ll j=1;j<=n+n;j++)
//		{
//			cout<<dis[i][j]<<" "; 
//		}
//		cout<<"\n"; 
//	}
//	cout<<"---\n"; 	
//	cout<<qq<<"q\n"; 
	while(qq--)
	{
//		cout<<qq<<"--\n";  
		ll x,y; 
		cin>>x>>y; 
		ll ans=MAXX; 
		for(ll i=1;i<=cnt[x];i++)
		{
			for(ll j=1;j<=cnt[y];j++)
			{
//				cout<<j<<" "<<t[x][i].id<<" "<<t[y][i].id+n<<" "<<t[x][i].tim+t[y][j].tim+dis[t[x][i].id][t[y][j].id+n]<<"--\n"; 
				ans=min(ans,t[x][i].tim+t[y][j].tim+dis[t[x][i].id][t[y][j].id+n]); 
			}
		}
		ans+=w[x]+w[y]; 
		cout<<ans<<"\n"; 
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

32
17


0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

35
16
*/

