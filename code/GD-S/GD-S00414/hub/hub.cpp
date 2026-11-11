#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=10005;
int vis[N];
vector<int> G[N];
int ans=0x3f3f3f3f;
int n,k;
deque<int> q;
vector<int> a;
int dis[N];
int dfs(int x){
	if(x==k){
		//统计距离
		int mx=0;
		memset(dis,0x3f,sizeof dis);
		queue<int> p;
		
		for(int i : a){
			dis[i]=0;
			for(int v : G[i]){
				if(vis[v]==0){
					p.push(v);
					dis[v]=1;
				}
			}
		}
//		bool into=false;
//		if(p.empty())cout<<"ept";//<<--
//		if(p.empty()){
//			cout<<"???:";
//			for(int i : a) cout<<i<<' ';
//			cout<<"\n";
//		}
		while(!p.empty()){
//			into=true;
			int u=p.front();
			p.pop();
			mx=max(mx,dis[u]);
//			if(dis[u]==0){
//				cout<<"unnormal zero:"<<u<<" "<<dis[u]<<"\n";
//			}
//			cout<<mx<<"\n";
			for(int v : G[u]){
				if(dis[v]==inf){
					dis[v]=dis[u]+1;
					p.push(v);
				}
			}
		}
//		if(mx==0){
//			cout<<"a:";
//			for(int i : a) cout<<i<<" ";
//			cout<<"\n";
//		}
//		if(!into) cout<<"skip the repeat\n";
//		cout<<mx<<" -mx\n";
		return mx;
	}
	if(q.empty()){
		return inf;
	}
	int ret=inf;
	int u=q.front();
	q.pop_front();
	ret=min(dfs(x+1),ret);
//	cout<<ret<<" -ret2\n";
	vis[u]=true;
	int cnt=0;
	for(int v : G[u]){
		if(!vis[v]){
			q.push_back(v);
			cnt++;
		}
	}
	a.push_back(u);
	ret=min(dfs(x+1),ret);
	a.pop_back();
	q.push_front(u);
	vis[u]=false;
	while(cnt--) q.pop_back();
//	cout<<ret<<" -ret\n";
	return ret;
}
int check(int i,int j){
	a.clear();
	a.push_back(i);
	a.push_back(j);
	q.clear();
	memset(vis,0,sizeof vis);
	vis[i]=true;
	vis[j]=true;
	for(int v : G[i]){
		if(!vis[v])q.push_back(v); 
	}
	for(int v : G[j]){
		if(!vis[v])q.push_back(v);
	}
	return dfs(2);
}
void work(){
	//init
	for(int i=1;i<=n;i++){
		G[i].clear();
	}
	memset(vis,0,sizeof vis);
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	if(k==n){
//		cout<<"FULL";
		cout<<0<<"\n";
		return;
	}
	ans=inf;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int temp=check(i,j);
//			cout<<temp<<"\n";
			ans=min(ans,temp);
		}
	}
	cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		work();
	}
	return 0;
}
/*
树上取两个联通点集，使树上各点距离【最大值最小】 
先选择两个点（枚举/随机），取距离最大点找祖先并选择直到选择了K个点
最长路径必然出现在【叶子节点】或者两个节点中间
递归预处理【来自两个连通块子树的最大距离】 
强制让最大距离出现在叶子节点
（如果中间更长，必然可以让叶子节点距离+1，中间距离-1） 
 拓扑排序
 储存：
 1.最大拓扑深度-到叶子的距离
 中间节点距离 
*/
