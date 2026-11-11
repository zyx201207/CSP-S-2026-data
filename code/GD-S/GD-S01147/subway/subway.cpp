#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5;
ll c,n,m,d,q,k,je,t;
ll w[N];
ll x,y;
bool vis[N];
struct st{
	ll x;
	ll time;
};
struct sh{
	ll jd;
	ll step;
};
vector<st> a[N];
ll bfs(ll f,ll la)
{
    ll ans=0x3f3f3f3f3f3f3f3f;
    queue<sh> q;
	q.push({f,0});
	vis[f]=1;
	while(q.size()){
		sh now=q.front();
		q.pop();
		if(now.jd==la)ans=min(ans,now.step);
		for(auto u:a[now.jd]){
			if(!vis[u.x]&&now.jd<=d){
			    vis[u.x]=1;
			    if(u.x>d)q.push({u.x,now.step});
			}
			else if(!vis[u.x]){
			    vis[u.x]=1;
			    q.push({u.x,now.step+u.time});
			}
		}
	}
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];	
	}
	for(ll i=1;i<=n;i++){
		cin>>k;
		for(ll j=1;j<=k;j++)
		{
			cin>>je>>t;
			a[i].push_back({je,t});
	        a[je].push_back({i+d,t});
        }
	}
	while(q--){
		cin>>x>>y;
		cout<<bfs(x,y)+w[x]+w[y]<<"\n";
	}
	return 0;
} 
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2
