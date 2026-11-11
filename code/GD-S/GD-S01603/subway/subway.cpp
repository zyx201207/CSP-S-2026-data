#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=4e5+10;
//cw [trainid][changewaste]
//sw startwaste
//s ¡Ÿ ±¥Ê∑≈
//g[trainid][stageid] 
int c,n,d,m,q,k;
ll sw[N],s[N],ans;
unordered_map<ll,vector<ll>> g[505];
ll cw[505][N],dis[N];
bool vis[N];
struct node{
	ll w,tid,sid;
	bool operator>(const node&other)const{
	    return w < other.w;
	}
};
ll bfs(int sx,int fx){
	fill(vis,vis+m+1,0);
	memset(dis,0x3f,sizeof(dis));
	dis[sx]=0;
	vis[sx]=1;
	priority_queue<node,vector<node>,greater<node> > q;
	for(int i=1;i<=n;i++){
		if(cw[i][sx]){
//			cout<<i<<endl;
			q.push({cw[i][sx],i,sx});
		}
	}
	while(!q.empty()){
		auto it=q.top();
		q.pop();
		ll w=it.w;
		ll tid=it.tid;
		ll sid=it.sid;
//		cout<<endl;
//		cout<<w<<endl;
		for(auto v:g[tid][sid]){
//			if(vis[v]) continue;
//			vis[v]=1;
//            cout<<g[tid][sid].size()<<" ";
			if(v==fx){
				return w+cw[tid][v];
			}
			
			for(int i=1;i<=n;i++){
				if(i==tid) continue;
				if(cw[i][v]){
//					cout<<w+cw[tid][v]+cw[i][sid]<<endl;
					q.push({w+cw[tid][v]+cw[i][sid],i,v});
				}
			}
		}
	}
}
int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>sw[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>s[j]>>cw[i][s[j]];
//			cout<<i<<" "<<s[j]<<" "<<cw[i][s[j]]<<endl;
		}
		for(int j=1;j<=k;j++){
			for(int l=j;l<=k;l++){
				g[i][s[j]].push_back(s[l]);
				g[i][s[l]].push_back(s[j]);
			}
		}
	}
	while(q--){
		int sx,fx;
		cin>>sx>>fx;
		ans=sw[sx]+sw[fx];
//		cout<<ans<<" ";
		ans+=bfs(sx,fx);
		cout<<ans<<endl;
	}
	return 0;
}
