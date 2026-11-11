#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505,M=5e5+5;
ll C,n,m,d,q,num,a[M],pos[M],cost[N][2005];
unordered_map<ll,ll>mp[N],vis[N];
struct node{
	ll v,id;
};vector<node>g[M];
struct mask{
	ll u,val,id;
	bool operator<(mask b)const{
		return val>b.val;
	}
};
int bfs(int s,int t){
	for(int i=1;i<=m;i++)vis[i].clear();
	priority_queue<mask>q;
	q.push({s,0,0});
	while(q.size()){
		mask f=q.top();
		q.pop();
	//	printf("%d %d %d\n",f.u,f.val,f.id);
		if(f.u==t)return f.val+a[s]+cost[f.id][mp[f.id][f.u]]+a[t];
		vis[f.id][f.u]=1;
		for(node i:g[f.u]){
			int v=i.v,id=i.id;
			if(vis[id][v])continue;
			if(f.id==0)q.push({v,f.val+cost[id][mp[id][f.u]],id});
			if(id==f.id)q.push({v,f.val,id});
			else{
				int wx=cost[f.id][mp[f.id][f.u]],wy=cost[id][mp[id][f.u]];
				q.push({v,f.val+wx+wy,id});
			}
		}
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		cin>>num;
		for(int j=1;j<=num;j++){
			cin>>pos[j]>>cost[i][j],mp[i][pos[j]]=j;//mp:i=id j=pos mean=num cost:i=id j=num mean=cost
			if(j>1){
				g[pos[j]].push_back({pos[j-1],i});
				g[pos[j-1]].push_back({pos[j],i});
			}
		}
	}
	int s,t;
	while(q--){
		cin>>s>>t;
		cout<<bfs(s,t)<<'\n';
	}
	return 0;
}
