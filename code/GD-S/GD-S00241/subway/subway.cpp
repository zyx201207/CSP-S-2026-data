#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,to,val,last,top;
int w[500005],k[505],siz[500005];
struct node{
	int to,val;
};
vector<node>g[10500510]; 
long long dis[10500510];
bool in[10500510];
priority_queue<pair<long long,int>>pq;
void solve(int st,int en){
	for(int i=1;i<=top;i++) dis[i]=1e15;
	dis[st]=0;
	in[st]=1;
	while(!pq.empty()) pq.pop();
	pq.push(make_pair(0,st));
	while(!pq.empty()){
		auto now=pq.top();
//		cout<<now.second<<'\n';
		pq.pop();
		in[now.second]=0;
		for(node i:g[now.second]){
			if(dis[now.second]+i.val<dis[i.to]){
				dis[i.to]=dis[now.second]+i.val;
				if(!in[i.to]){
					in[i.to]=1;
					pq.push(make_pair(dis[i.to]*-1,i.to));
				}
			}
		}
	}
	cout<<dis[en]+w[st]+w[en]<<'\n';
}
inline int read(){
	char c;
	long long f=1,num=0;
	c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		num=num*10+(c-'0');
		c=getchar();
	}
	return f*num;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	top=m+n;
	for(int i=1;i<=m;i++) cin>>w[i]; 
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>to>>val;
//			id1[to][++siz[to]]=++top;
//			id2[to][siz[to]]=i;
			top++;
			g[m+i].push_back({top,0});
			g[top].push_back({m+i,0});
			g[to].push_back({top,val});
			g[top].push_back({to,val});
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		solve(u,v);
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
