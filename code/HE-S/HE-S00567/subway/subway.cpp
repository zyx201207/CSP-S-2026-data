#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+50;
ll head[N],to[N],nxt[N],val[N],cnt;
void add(ll x,ll y,ll z){
	nxt[++cnt]=head[x];
	to[cnt]=y;
	val[cnt]=z;
	head[x]=cnt;
}
ll c,n,m,d,qq;
ll w[N];
ll a[555][1100];
ll t[555][1100];
ll k[N];
ll e[N];
ll f[N];
ll vis[N];
priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > q;
void dij(ll s){
	memset(f,0x3f,sizeof(f));
	f[s]=0;
	q.push({0,s});
	while(!q.empty()){
		pair<int,int > p=q.top();
		q.pop();
//		cout<<"KKK\n";
		for(int i=head[p.second];~i;i=nxt[i]){
			ll j=to[i];
//			cout<<j<<"\n";
			if(f[j]>f[p.second]+val[i]+e[j]){
				f[j]=f[p.second]+val[i]+e[j];
//				cout<<j<<" "<<f[j]<<"\n";
				q.push({f[j],j});
			}
		}
	}
}
map<pair<ll,ll>,ll> mp;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	memset(head,-1,sizeof(head));
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			if(j>1) mp[{a[i][j],a[i][j-1]}]=1;
			e[a[i][j]]=t[i][j];
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i==j) continue;
			if(!mp[{i,j}])continue;
			add(i,j,e[i]);
			add(j,i,e[j]);
		}
	}
	while(qq--){
		int x,y;
		cin>>x>>y;
		dij(x);
		cout<<f[2]<<"\n";
		cout<<w[x]+f[y]+e[y]+w[y]<<"\n";
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
*/
