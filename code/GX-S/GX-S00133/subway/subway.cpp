#include<bits/stdc++.h>
#define f(i,e,s) for(int i=e;i<=s;i++)
#define pii pair<long long,long long>
using namespace std;
typedef long long ll;
const ll N=5e5+10,G=5e2+8,inf=0x3f3f3f3f3f3f3f3f;
ll c,n,m,d,q;
struct node
{
	ll y,z,id;
};
vector<node> g[N];
ll a[N];
ll sta[N],dis[4090][4090],vis[4090];
void dij(ll st)
{
	priority_queue<pair<ll,pair<ll,ll> > > q;
	q.push({sta[st]-1,{st,0}});
	f(i,1,m) dis[st][i]=inf;
	dis[st][st]=sta[st]-1;
	vis[st]=1;
	while(q.size())
	{
//		cnt++;
//		if(cnt>=999999)
//		{
//			cout<<"timeout!!!";
//			return;
//		}
		ll x=q.top().second.first,idd=q.top().second.second;
//		cout<<x<<endl;
		q.pop();
		for(int i=0;i<(int)g[x].size();i++)
		{
			ll y=g[x][i].y,z=g[x][i].z,id=g[x][i].id;
//			cout<<y<<endl;
			if(idd!=id) z+=sta[x]-1;
			if(st==x && z-(sta[x]-1)==g[x][i].z) z=g[x][i].z;
//			if((y==2 || y==3) && z-(sta[y]-1)==g[x][i].z) cout<<x<<" "<<y<<" "<<idd<<" "<<id<<endl;
//			cout<<dis[st][x]+z<<" "<<dis[st][y]<<endl;
			if(dis[st][x]+z<dis[st][y] || dis[st][x]==inf)
			{
				dis[st][y]=dis[st][x]+z;
//				if(dis[st][y]==22)
//				{
//					cout<<idd<<" "<<id<<endl;
//					cout<<x<<" "<<y<<" "<<g[x][i].z<<endl<<endl;
//				}
				q.push({z,{y,id}});
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	f(i,1,m) cin>>a[i];
	f(i,1,n)
	{
		ll k;
		cin>>k;
		ll x=0,y,z;
		f(j,1,k)
		{
			cin>>y>>z;
			if(j==1) sta[y]=z+1;
			g[x].push_back({y,z,i});
			x=y;
		}
	}
	f(i,1,n)
	{
		if(sta[i]) dij(i);
	}
//	for(int i=0;i<(int)g[2].size();i++) cout<<g[2][i].y<<" ";
//	cout<<endl;
//	f(i,0,m)
//	{
//		for(int j=0;j<(int)g[i].size();j++)
//		{
//			cout<<i<<" "<<g[i][j].y<<" "<<g[i][j].z<<" "<<g[i][j].id<<endl;
//		}
//	}

//	cout<<endl;
//	f(i,1,m)
//	{
//		if(!sta[i]) continue;
//		f(j,1,m)
//		{
//			cout<<i<<" "<<j<<" "<<dis[i][j]<<endl;
//		}
//	}

	while(q--)
	{
		ll x,y;
		cin>>x>>y;
		cout<<dis[x][y]+a[x]+a[y]<<endl;
	}
	return 0;
}























































