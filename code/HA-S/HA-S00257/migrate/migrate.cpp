
#include<bits/stdc++.h>
using namespace std;
#define maxn 200009
#define endl '\n'
#define int long long
struct edge{
	int to,w;
};
struct node{
	int id,d;
	bool operator<(const node&h)const{
		return h.d<d;
	}
};
priority_queue<node>q;
vector<edge>e[maxn];
int dis[maxn],vis[maxn],a[maxn];
void dijkstra(int s){
	dis[s]=0;
	q.push({s,0});
	while(!q.empty()){
		auto o=q.top();
		q.pop();
		int id=o.id,d=o.d;
		if(dis[id]==d){//若dis一样，那么说明这是一条新路 
			vis[id]++;//vis++
		//	continue;//由于已经访问，已经对其他松驰过了，所以直接continue 
		}else{//否则dis一定会更新为更小的，访问次数为一 
			if(vis[id])continue;
			dis[id]=d; 
			vis[id]=1;//因为更小所以不能continue（要去松驰其他） 
		}
		for(auto x:e[id]){//对id的每个出边进行松驰 
			int to=x.to,w=x.w;
			if(dis[to]>=dis[id]+w){
				dis[to]=dis[id]+w;
				q.push({to,dis[to]});//更优，加入新状态 
			}
		}
	}
} 
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	int xblue,t;cin>>xblue>>t;
	long long ans=0;
	while(t--){
		int n,d;cin>>n>>d;
		
		ans=0; 
		for(int i=1;i<=n;i++){
			e[i].clear();
		}memset(dis,2000000000000000090,sizeof dis);
		memset(vis,0,sizeof vis);//多测清空 
		
		for(int i=1;i<=n;i++){//读入坐标 
			cin>>a[i];
		}for(int i=1;i<=n;i++){//建图 ，双向边 
			for(int j=i+1;j<=n;j++){
				int k=a[j]-a[i];
				if(k<=d){
					e[i].push_back({j,1});
					e[j].push_back({i,1});
				}
			}
		}//预处理图
		
		
		for(int i=1;i<=n;i++){//暴力枚举起点 
			memset(dis,2000000000000000090,sizeof dis);
			memset(vis,0,sizeof vis);//清空上个起点数据 
			
			dijkstra(i);
			for(int j=1;j<=n;j++){
				if(vis[j]==2){//若有两次 
					ans++;//ans++
				}
			}
		}cout<<ans/2<<endl;
	}
	return 0;
}
/*
rp++
It's my own sunset 
I may AFO after CSP 2026
-J is difficult ,but -S T1 is easier than -J T2?
I can only get ≈200 in -J
I can only get 100+ in -S
I have studied OI for 1.5 years
but I am fw
I am chusaner
Luogu ID: includeYYB
xblue is so strong that he can get 388 in -J
I am Fwer 
good bye
*/


 
 
 
 
 

