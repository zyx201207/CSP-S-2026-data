#include<bits/stdc++.h>
using namespace std;
int n,m,c,k,p,q,x,y,z,l,r,d,g[100005],g2[100050],a[250005],b[505][20055],dis[1005][1005];
bool f;
struct node{
	int v,w;
};

vector<node>v[1005];
bool operator<(node a,node b){
	return a.w>b.w;
}
int main(){
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
cin>>c>>n>>m>>d>>q;
for(int i=1;i<=m;i++){
	cin>>a[i];
}
for(int i=1;i<=n;i++){
	cin>>k;
	
	cin>>x>>y>>z>>c;
	v[x].push_back({z,y+c});
	v[z].push_back({x,y+c});
}
for(int i=1;i<=q;i++){
	cin>>x>>y;
	if(dis[x][y]){
		cout<<dis[x][y]+a[x]+a[y]<<'\n';
		continue;
	}
    priority_queue<node>q;
    q.push({x,0});
    while(!q.empty()){
    	node t=q.top();
    	q.pop();
		if(dis[x][t.v]){
    		continue;
    		
		}
    	dis[x][t.v]=t.w;
    	
		for(auto j:v[t.v]){
			q.push({j.v,dis[x][t.v]+j.w});
		}
	}
	cout<<dis[x][y]+a[x]+a[y]<<'\n';
}
return 0;
}
