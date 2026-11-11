 #include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=510,M=5e5+10;
int c,n,m,d,q,ting;
ll dis[M],w[M],T;
vector<pair<int,int> > a[M];
void dij(int s)
{
vector<bool> vis(N,0);
priority_queue<pair<ll,int> ,vector<pair<ll,int> >,greater<pair<ll,int> > >q;
q.push({0,s}); dis[s]=0;
while(!q.empty())
{
int x=q.top().second; q.pop();
if(vis[x]) continue;
vis[x]=1;
for(auto Y:a[x])
{
int y=Y.first,w=Y.second;
if(dis[y]>dis[x]+w)
{
dis[y]=dis[x]+w;
q.push({dis[y],y});
}
}
}
}
signed main()
{
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout); 
cin.tie(0); cout.tie(0);
cin>>c>>n>>m>>d>>q;
ting=m+1;
for(int i=1;i<=m;i++) cin>>w[i];
for(int i=1;i<=n;i++)
{
int k,x,t;
cin>>k>>x>>t;
T=t; 
a[ting].push_back({x,1});
a[x].push_back({ting,1});
for(int j=2,pre=x;j<=k;j++)
{
cin>>x>>t;
a[pre].push_back({x,0});
a[ting].push_back({x,1});
a[x].push_back({ting,1});
}
}
for(int i=1;i<=q;i++)
{
memset(dis,0x3f,sizeof(dis));
int x,y;
cin>>x>>y;
dij(x);
//
for(int j=1;j<=m;j++) cout<<j<<' '<<dis[j]<<"\n";
//
cout<<"\n-----------\n";
cout<<w[x]+1ll*dis[y]*T+w[y]<<"\n";
}
return 0;
} 
 
                      
