#include<bits/stdc++.h>
using namespace std;
int c,s,n,m,t,vis[2000],dis[2000];
struct bian{
	int w,v,vw;
};
struct node{
	int x,dis;
};
bool operator<(const node&x,const node&y){
	return y.dis<x.dis;
}
vector<bian>e[2000];
priority_queue<node>q;
void dj(int s){
	for(int i=1;i<=n;i++)dis[i]=INT_MAX;
	dis[s]=0;
	q.push({s,0});
	while(!q.empty()){
		int u=q.top().x,d=q.top().dis;
		if(dis[u]<d+e[s].w)
	}
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	cin>>c>>s>>n>>m>>t;
	for(int i=1;i<=n;i++)cin>>dis[i];
	for(int i=1;i<=s;i++){
		int nu;
		cin>>nu;
		int a,b,c,d;
		cin>a>>b>>c>>d;
		e[a].push_back({b,c,d});
	}
	for(int i=1;i<=t;i++){
		int l,r;
		cin>>l>>r;
		dj(l);
		cout<<dis[l]<<'\n';
	}
	return 0;
} 
