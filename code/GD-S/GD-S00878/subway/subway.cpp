#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int maxn=2e5+5,mod=1e9+7;
ll w[maxn];
struct node{
	ll to,w;
};
struct e{
	ll d,w;
	bool operator<(const e &a)const{return w>a.w;}
};
vector<node> a[maxn];
ll dis[maxn];
bool vis[maxn];
ll c,n,m,d,q;
void dij(int s){
	priority_queue<e> q;
	q.push({s,0});
	for (int i=1;i<=m+n;i++) vis[i]=0,dis[i]=2e18;
	dis[s]=0;
	while (!q.empty()){
		e r=q.top();
		q.pop();
		if (vis[r.d]) continue;
		vis[r.d]=1;
		for (int i=0;i<a[r.d].size();i++){
			node j=a[r.d][i];
			if (dis[j.to]>r.w+j.w){
				dis[j.to]=r.w+j.w;
				q.push({j.to,dis[j.to]});
			}
		} 
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for (int i=1;i<=n;i++){
		int k;
		scanf("%lld",&k);
		for (int j=1;j<=k;j++){
			ll x,y;
			scanf("%lld %lld",&x,&y);
			a[i+m].push_back({x,y});
			a[x].push_back({i+m,y});
		}
	}
	while (q--){
		int x,y;
		scanf("%lld %lld",&x,&y);
		dij(x);
		cout<<dis[y]+w[x]+w[y]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


