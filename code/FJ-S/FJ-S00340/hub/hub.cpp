#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,k;
int u,v; 
int ans=1e18;
bool vis[1000005];//这个位置有没有被选
bool b[1000005]; 
vector<int>vc[1000005];
int dfs(int u){
	if(vis[u]){
		return 0;
	}
	b[u]=1;
	int mx=1;
	for(auto v:vc[u]){
		if(b[v]){
			continue;
		}
		mx=max(mx,dfs(v)+1);
	}
	return mx;
}
void chose(int cnt,int deep,int ct){//已经决策了几个,当前选到第几个,连痛快数量 
	if(deep>n&&cnt!=k){
		return;
	}
	if(deep>n){
		for(int i=1;i<=n;i++){
			b[i]=0;
			if(vis[i]){
//				cout<<i<<" ";
			}
		}
//		cout<<"\n";
		int mx=0;
		for(int i=1;i<=n;i++){
			if(vis[i]){
				for(auto j:vc[i]){	
					mx=max(mx,dfs(j));
				}
			}
		}
//		cout<<mx<<":\n";
		ans=min(ans,mx);
		return;
	}
	if(cnt>k){
		return;
	}
	if(n-deep+1+cnt<k){
		return;
	}
	if(ct>2){
		return;
	}
	chose(cnt,deep+1,ct);
	for(auto v:vc[u]){
		if(vis[v]){
			vis[deep]=1;
			chose(cnt+1,deep+1,ct);
			vis[deep]=0;
			return;
		}
	}
	vis[deep]=1;
	chose(cnt+1,deep+1,ct+1);
	vis[deep]=0;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		ans=1e18;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			vc[i].clear();
			vis[i]=0;
			b[i]=0;
		}
		for(int i=1;i<n;i++){
			cin>>u>>v;
			vc[u].push_back(v);
			vc[v].push_back(u);
		}
		chose(0,1,0);
		if(ans==1e18){
			cout<<"1\n";
			continue;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
