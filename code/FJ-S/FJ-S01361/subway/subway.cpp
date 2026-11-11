#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q,w[1010],k,wa[1010][1010];
vector<array<int,2>> node[1010];
bool b[1010];
ll c_k,c_a[1010][1010],c_t[1010][1010],c_wa1[110][310][310],c_num,c_b[1010];
void dfs(int x,int y,int num){
	if(x==y){
		if(c_num) c_num=min(c_num,num*1LL);
		else c_num=num;
		return;
	}
	for(int j=1;j<=n;j++){
		for(int i=1;i<=m;i++){
			if(c_b[i]==0&&c_wa1[j][x][i]!=0){
				c_b[i]=1;
				dfs(i,y,num+c_wa1[j][x][i]);
				c_b[i]=0;
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	priority_queue<array<int,2>> a;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	if(c>=1&&c<=6){
		for(int i=1;i<=n;i++){
			cin>>c_k;
			for(int j=1;j<=c_k;j++){
				cin>>c_a[i][j]>>c_t[i][j];
			}
			for(int i1=1;i1<c_k;i1++){
				for(int j=i1+1;j<=c_k;j++){
					c_wa1[i][c_a[i][i1]][c_a[i][j]]=c_t[i][i1]+c_t[i][j];
					c_wa1[i][c_a[i][j]][c_a[i][i1]]=c_t[i][i1]+c_t[i][j];
				}
			}
		}
		for(int i=1;i<=q;i++){
			int c_x,c_y;
			cin>>c_x>>c_y;
			c_num=0;
			c_b[c_x]=1;
			dfs(c_x,c_y,0);
			c_b[c_x]=0;
			cout<<c_num+w[c_x]+w[c_y]<<"\n";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		int a11,a12,t11,t12;
		if(k==1){
			cin>>a11>>t11;
			continue;
		}
		cin>>a11>>t11>>a12>>t12;
		node[a11].push_back({a12,t11+t12});
		node[a12].push_back({a11,t11+t12});
	}
	while(q--){
		int start_node,end_node;
		cin>>start_node>>end_node;
		if(wa[start_node][end_node]){
			cout<<wa[start_node][end_node]+w[start_node]+w[end_node]<<"\n";
			continue;
		}
		for(int i=1;i<=m;i++) b[i]=0;
		b[start_node]=1;
		priority_queue<array<ll,2>> qu;
		qu.push({0,start_node});
		while(qu.size()){
			auto g=qu.top();
			qu.pop();
			ll w1=-g[0],u=g[1];
//			cout<<u<<"-"<<w1<<"\n";
			for(auto vv:node[u]){
				ll w2=vv[1],v=vv[0];
				if(wa[start_node][v]!=0) wa[start_node][v]=min(wa[start_node][v],w1+w2);
				else wa[start_node][v]=w1+w2;
				if(b[v]) continue;
				qu.push({-wa[start_node][v],v});
				b[v]=1;
//				cout<<v<<"--"<<w2<<"--"<<w1+w2<<"--"<<wa[start_node][v]<<"\n";
			}
		}
		cout<<wa[start_node][end_node]+w[start_node]+w[end_node]<<"\n";
	}
	return 0;
}
