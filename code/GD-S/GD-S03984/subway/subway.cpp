#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll c,n,m,d,q,w[500010];
struct node{
	ll a,t;
};
bool vis[500010];
vector<node> v[500010]; 
struct stu{
	ll x,sum;
};
ll bfs(ll x,ll y){
	queue<stu> q;
	for(int i=1;i<=n;i++){
		vis[i]=0;
	}
	q.push({x,w[x]});
	vis[x]=1;
	while(q.size()){
		stu r=q.front();
		q.pop();
		vis[r.x]=1;
		if(r.x==y){
			return (r.sum+w[y]);
		} 
		for(int i=0;i<v[r.x].size();i++){
			node p=v[r.x][i];
			ll j=p.a;
			if(!vis[j]){
				q.push({j,p.t+r.sum+w[j]});
			}
		}
	}
	return -1;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		ll k=0;
		cin>>k;
		for(int j=1;j<=k;j++){
			int t,a;
			cin>>a>>t;
			v[i].push_back({a,t});
			v[a].push_back({i,t});
		}
		
	}
	for(int i=1;i<=q;i++){
		ll x,y;
		cin>>x>>y;
		cout<<bfs(x,y)<<endl;
	}
	return 0;
}
