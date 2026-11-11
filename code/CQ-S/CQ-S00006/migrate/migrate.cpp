#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,T,x[200005];
vector<ll>a[200005];
ll n,d;
struct node{
	ll s,dis;
	bool operator <(const node&x)const{
		return dis>x.dis;
	}
};
ll dis[200005],way[200005],ans;
void dij(ll u){
	for(ll i=1;i<=n;i++)dis[i]=INT_MAX,way[i]=0;
	priority_queue<node>q;
	q.push(node{u,0});
	dis[u]=0;
	while(!q.empty()){
		node t=q.top();
		q.pop();
		ll x=t.s,y=t.dis;
		for(auto v:a[x]){
			if(y+1<=dis[v]){
				if(y+1==dis[v])way[v]++;
				else way[v]=0;
				dis[v]=y+1;
				q.push(node{v,y+1});
			}
		}
	}
	for(ll i=1;i<=n;i++){
		if(way[i]==1)ans++;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		for(ll i=1;i<=n;i++)a[i].clear();
		ans=0;
		cin>>n>>d;
		for(ll i=1;i<=n;i++){
			cin>>x[i];
		}
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d)a[i].push_back(j) ;
				else break;
			}
		}
		for(ll i=1;i<=n;i++){
			dij(i);
		}
		cout<<ans<<endl;
	}
}

