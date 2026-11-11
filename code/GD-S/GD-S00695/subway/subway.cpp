#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
struct node{long long a,t;}qwq[maxn];
long long w[maxn],dis[maxn];
int k[maxn];
vector<pair<int,long long>>G[maxn];
inline void dji(int s){
	priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>qp{};
	memset(dis,0x3f,sizeof(dis)),dis[s]=0;
	qp.push({0,s});
	while(!qp.empty()){
		pair<long long,int> nw=qp.top();qp.pop();
		if(nw.first>dis[nw.second])continue;
		for(pair<int,long long> v : G[nw.second]){
			if(dis[v.first]>v.second+dis[nw.second]){
				dis[v.first]=v.second+dis[nw.second];
				qp.push({v.second+dis[nw.second],v.first});
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//É¾×¢ÊÍ
	int c,n,m,d,t_;cin>>c>>n>>m>>d>>t_;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int i=1;i<=k[i];i++){
			cin>>qwq[i].a>>qwq[i].t;
			G[(i-1)*d+i+m].emplace_back(qwq[i].a,qwq[i].t);
			G[qwq[i].a].emplace_back((i-1)*d+i+m,qwq[i].t);			
		}
		for(int i=1;i<k[i];i++){
			G[(i-1)*d+i+m+1].emplace_back((i-1)*d+i+m,0);
			G[(i-1)*d+i+m].emplace_back((i-1)*d+i+m+1,0);
		} 
	}
	while(t_--){
		int st,ed;cin>>st>>ed;
		dji(st);
		cout<<w[st]+w[ed]+dis[ed]<<'\n';
	}
	return 0;
} 



//#include<bits/stdc++.h>
//using namespace std;
//const int maxn=500005;
//struct node{long long a,t;}qwq[maxn];
//long long w[maxn],dis[maxn];
//int k[maxn];
//vector<pair<int,long long>>G[maxn];
//inline void dji(int s,int n){
//	priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>qp{};
//	memset(dis,0x3f,sizeof(dis)),dis[s]=0;
//	qp.push({0,s});
//	while(!qp.empty()){
//		pair<long long,int> nw=qp.top();qp.pop();
//		if(nw.first>dis[nw.second])continue;
//		for(pair<int,long long> v : G[nw.second]){
//			if(dis[v.first]>v.second+dis[nw.second]){
//				qp.push({v.second+dis[nw.second],v.first});
//			}
//		}
//	}
//}
//int main(){
//	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
////	freopen("subway.in","r",stdin);
////	freopen("subway.out","w",stdout);
////É¾×¢ÊÍ
//	int c,n,m,d,t_;cin>>c>>n>>m>>d>>t_;
//	for(int i=1;i<=m;i++)cin>>w[i];
//	int S=n;
//	for(int i=1;i<=n;i++){
//		cin>>k[i];
//		for(int i=1;i<=k[i];i++){
//			cin>>qwq[i].a>>qwq[i].t;
//			G[i+S].emplace_back(qwq[i].a,qwq[i].t);
//			G[qwq[i].a].emplace_back(i+S,qwq[i].t);			
//		}
//		for(int i=1;i<k[i];i++){
//			G[S+i].emplace_back(S+i+1,0);
//			G[S+i+1].emplace_back(S+i,0);
//		} 
//		S+=k[i];
//	}
//	while(t_--){
//		int st,ed;cin>>st>>ed;
//		dji(st,n+S);
//		cout<<w[st]+w[ed]+dis[ed]<<'\n';
//	}
//	return 0;
//} 
