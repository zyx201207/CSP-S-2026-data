#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,h[N],cnt,c,t,k;
int vis[N],tim[N],ans,final_ans;
struct node{int next,to;}r[N<<1];
inline void add(int u,int v){
	cnt++;
	r[cnt].to=v;
	r[cnt].next=h[u];
	h[u]=cnt;
}
bool mp[N];
inline void make_tree(int u,int prt){
	mp[u]=1;
	for(int i=h[u];i;i=r[i].next){
		int v=r[i].to;
		if(v==prt||vis[v])continue;
		make_tree(v,u);
	} 
}
inline void _find(int u,int dep,int rt){
	if(dep>ans)return;
	tim[u]=rt;
	if(!vis[u]){ans=min(dep,ans);return;}
	for(int i=h[u];i;i=r[i].next){
		int v=r[i].to;
		if(tim[v]==rt)continue;
		_find(v,dep+1,rt);
	}
}
inline void dfs(int dep,int val){
	if(val+(n-dep+1)<k)return;
	if(dep==n+1){
		int _cnt=0,res=0;
		for(int i=1;i<=n;i++)mp[i]=0,tim[i]=0;
		for(int i=1;i<=n;i++)
			if(!mp[i]&&!vis[i])make_tree(i,0),_cnt++;
		if(_cnt>2)return ;
		for(int i=1;i<=n;i++){
			ans=n+1; 
			if(vis[i]){
				_find(i,0,i);
				res=max(res,ans);
			}
		}
	//	for(int i=1;i<=n;i++)cout<<vis[i]<<" ";
		//cout<<endl<<res<<" "<<k<<endl;
		final_ans=min(final_ans,res);
	}
	if(val<k)
	vis[dep]=0,dfs(dep+1,val+1);
	vis[dep]=1,dfs(dep+1,val);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout); 
	cin>>c>>t;
	while(t--){
		cin>>n>>k;final_ans=n+1;
		cnt=0;for(int i=1;i<=n;i++)h[i]=0;
		for(int i=1,u,v;i<=n-1;i++)
			cin>>u>>v,add(u,v),add(v,u);
		dfs(1,0);
		cout<<final_ans<<endl;
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10



*/
