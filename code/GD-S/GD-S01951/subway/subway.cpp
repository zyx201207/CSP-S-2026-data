#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll c,n,m,d,q,w[N],ans,f[N];
struct node{
	ll x,y;
};
vector<node> a[510],e[510];
vector<ll> b[N];
bool v[N];
void dfs(ll p,ll res,ll pos,ll goal){
	for(node t:a[p])
		if(t.x==pos){
			res+=t.y;
			break;
		}
	if(res>=f[p]&&res>=ans)
		return;
	f[p]=res;
	for(node t:a[p])
		if(t.x==goal){
			ans=min(ans,res+t.y+w[t.x]);
			return;
		}
	for(node t:e[p])
		for(ll T:b[t.x])
			if(!v[T]){
				v[T]=1;
				dfs(T,res+t.y,t.x,goal);
				v[T]=0;
			}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,x,y;j<=k;j++){
			cin>>x>>y;
			a[i].push_back({x,y});
			b[x].push_back(i);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<a[i].size();j++)
			if(b[a[i][j].x].size()>1)
				e[i].push_back({a[i][j].x,a[i][j].y});
	}
	for(int i=1,s,t;i<=q;i++){
		memset(f,0x3f,sizeof(f));
		ans=1e18;
		cin>>s>>t;
		for(ll T:b[s]){
			v[T]=1;
			dfs(T,w[s],s,t);
			v[T]=0;
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
