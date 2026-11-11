#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=1e6+10,inf=0x3f3f3f3f3f3f3f3f;

void solve();
bool check(ll x);

ll t,n,k,u,v,c;
vector<ll>edge[maxn];
ll dis[maxn],lsDis[maxn];//距离k的dis 距离最近交点的dis
ll du[maxn],vis[maxn];

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)solve();
	return 0;
}

void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)edge[i].clear();
	for(int i=1;i<n;i++){
		cin>>u>>v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	
	ll l=1,r=n,mid,ans=inf;
	while(l<=r){
		mid=l+r>>1;
//		cout<<mid<<' ';
		if(check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}cout<<ans<<endl;
}

bool check(ll x){
	for(int i=1;i<=n;i++)dis[i]=lsDis[i]=vis[i]=0;
	for(int i=1;i<=n;i++)du[i]=edge[i].size();
	vector<ll>pos;
	queue<ll>q;
	for(int i=1;i<=n;i++)if(du[i]==1)q.push(i);
	ll cnt=0,tmp=0;
	while(!q.empty()){
		ll u=q.front();
//		cout<<u<<' ';
		q.pop();
		if(dis[u]==x){
			dis[u]=-x;
			lsDis[u]=0;
			vis[u]=1;
			pos.push_back(u);
			cnt++;
		}if(vis[u]>=2){
			vis[u]=1;
			if(dis[u]!=-x)pos.push_back(u);
		}
		for(ll v:edge[u]){
			if(du[v]==1)continue;
			if(--du[v]==1)q.push(v);
			dis[v]=max(dis[v],dis[u]+1);
			if(vis[u]){
				lsDis[v]=max(lsDis[v],lsDis[u]+1);
				tmp++;
			}
			vis[v]+=vis[u];
		}
	}for(int i=0;i<pos.size();i++){
		pos[i]=lsDis[pos[i]];
	}sort(pos.begin(),pos.end());
	
//	cout<<x<<' '<<tmp<<' '<<pos.size()<<endl;
//	for(int i=1;i<=n;i++)cout<<dis[i]<<" \n"[i==n];
//	for(int i=1;i<=n;i++)cout<<lsDis[i]<<" \n"[i==n];
//	for(int i=1;i<=n;i++)cout<<vis[i]<<" \n"[i==n];
	ll P=0;
	if(pos.size()>1)P=pos[pos.size()-1]-1;
//	cout<<P<<endl;
	return (tmp-P<=k);
}/*
0 1
5 2
1 2
2 3
3 4
4 5
*/
