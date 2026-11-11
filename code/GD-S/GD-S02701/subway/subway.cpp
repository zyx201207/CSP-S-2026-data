#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
#define int long long
int dq[N],ans[N];
struct node2{
	int s,e,id,ans;
}ses[N];
bool cmp1(node2 gy,node2 yj){
	return gy.s < yj.s;
}
bool cmp2(node2 gy,node2 yj){
	return gy.id < yj.id;
}
struct node{
	int v,w;
	bool operator <(const node &l)const{
		return w > l.w;
	}
};
vector<node>g[20*N];
int c,n,m,d,q;
int w[N];
int dis[N];
bool vis[N];
void ini(){
	for(int i = 1;i <= n+m;i ++){
		dis[i] = LLONG_MAX;
		vis[i] = 0;
	}
}
void djk(int s){
	dis[s] = 0;
	vis[s] = 1;
	priority_queue<node>qp;
	for(auto z : g[s]){
		//cout << 
		if(dis[z.v] > dis[s]+z.w){
			dis[z.v] = dis[s]+z.w;
			//cout << "fff";
			//cout <<s<<" "<<z.v<<" "<< dis[z.v]<<'\n';
			qp.push({z.v,dis[z.v]});
		}
	}
	while(!qp.empty()){
		auto p = qp.top();
		qp.pop();
		vis[p.v] = 1;
		for(auto z : g[p.v]){
			if(vis[z.v])continue;
			if(dis[z.v] > dis[p.v]+z.w){
				dis[z.v] = dis[p.v]+z.w;
				//cout <<p.v<<" "<<z.v<<" "<< dis[z.v]<<'\n';
				qp.push({z.v,dis[z.v]});
			}
		}
	}
}
int ltl[30][30];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i ++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i ++){
		int k;
		cin >> k;
		for(int j = 1;j <= k;j ++){
			int a,t;
			cin >> a >> t; 
			g[m+i].push_back({a,t});
			g[a].push_back({m+i,t});
		}
	}
//	for(int i = 1;i <= m+n+1;i ++){
//		cout << i<<":";
//		for(auto z : g[i]){
//			cout << "("<<z.v<<","<<z.w<<")";
//		}
//		cout <<'\n';
//	}
	for(int i = m+1;i <= m+n;i ++){
		ini();
		djk(i);
		for(int j = m+1;j <= m+n;j ++){
			g[i].push_back({j,dis[j]});
			g[j].push_back({i,dis[j]});
		}
	} 

	for(int i = 1;i <= q;i++){
		cin >> ses[i].s >> ses[i].e;
		ses[i].id = i;
	}
	sort(ses+1,ses+1+q,cmp1);
//	for(int i = 1;i <= q;i++){
//		cout << ses[i].s<<" "<<ses[i].e<<" "<<ses[i].id<<'\n';
//	}
	for(int i = 1;i <= q;i++){
		if(ses[i].s!=ses[i-1].s){
			ini();
			djk(ses[i].s);
		}
		ses[i].ans = dis[ses[i].e]+w[ses[i].s]+w[ses[i].e];
	}
	sort(ses+1,ses+1+q,cmp2);
	for(int i = 1;i <= q;i++){
		//cout << ses[i].s<<" "<<ses[i].e<<" "<<ses[i].id<<" ";
		cout <<ses[i].ans<<'\n';
	}
	return 0;
} 
