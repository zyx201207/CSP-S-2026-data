#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int u,v;
};
int c,n,m,d,q,ks[500005],dist[20000005],vis[20000005];
vector<vector<node> > v(20000005);
deque<node> dq;
void dqsort(node dst){
	stack<node> st;
	while(!dq.empty() && dst.v<dq.back().v){
		st.push(dq.back());
		dq.pop_back();
	}
	dq.push_back(dst);
	while(!st.empty()){
		dq.push_back(st.top());
		st.pop();
	}
	return ;
}
void dij(int s,int e){
	dist[s]==0;
	vis[s]=true;
	dq.push_back(node{s,0});
	while(!dq.empty()){
		node temp=dq.front();
		dq.pop_front();
		dist[temp.u]=min(dist[temp.u],temp.v);
		for(int i=0;i<v[temp.u].size();i++){
			if(!vis[v[temp.u][i].u]){
				vis[v[temp.u][i].u]=true;
				dqsort(node{v[temp.u][i].u,temp.v+v[temp.u][i].v});
			}
		}
	}
	return ;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		int w;
		cin>>w;
		v[i].push_back(node{m+i,w});
		v[m+i].push_back(node{i,w});
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		ks[i]=ks[i-1]+k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			v[m+a].push_back(node{2*m+i,t});
			v[2*m+i].push_back(node{m+a,t});
		}
	}
	while(q--){
		int rx,ry;
		cin>>rx>>ry;
		for(int i=1;i<=2*m+n;i++){
			dist[i]=1e18;
			vis[i]=false;
		}
		dij(rx,ry);
		cout<<dist[ry]<<endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
