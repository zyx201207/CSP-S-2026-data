#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;
const int N=5e5+5,INF=1e9;
ll w[N];
bool vis[N];
vector<pll>a[N];
int c,n,m,d,q,k,ans;
void dfs(int s,int z,int time){
	vis[s]=1;
	if(s==z){
		ans=min(ans,time);
		return ;
	}
	if(time>ans)return ;
	for(auto e:a[s]){
		int next=e.first;
		int tm=e.second;
		if(vis[next]==0){
			dfs(next,z,time+tm+w[next]);	
			vis[next]=1;
		}	
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		while(k--){
			int v,w;
			cin>>v>>w;
			a[i].push_back({v,w});
			a[v].push_back({i,w});
		}					
	}
	for(int i=1;i<=q;i++){
		ans=INF;
		int l,r;
		cin>>l>>r;
		dfs(l,r,w[l]);
		cout<<ans<<"\n";
	}
}
