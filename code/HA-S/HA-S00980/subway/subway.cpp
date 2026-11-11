#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int c,n,m,d,q,a[5000050],k[500050],t[505][500005],l,r;
bool vis[500050];
struct node{
	int x,y;
};
vector<node> v[500050];
struct node1{
	int x,y,z;
};
int bfs(){
	int ans=2e9;
	memset(vis,0,sizeof(vis));
	queue<node1> q;
	for(int i=0;i<v[l].size();i++){
		q.push({v[l][i].x,t[v[l][i].y][l],v[l][i].y});
	}
	while(!q.empty()){
		int x=q.front().x,y=q.front().y,z=q.front().z;
		q.pop();
		if(x==r){
			ans=min(ans,y+t[z][x]);
		}
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=0;i<v[x].size();i++){
			if(v[x][i].y!=z){
				q.push({v[x][i].x,t[v[x][i].y][x]+y+t[z][x],v[x][i].y});
			}
			else{
				q.push({v[x][i].x,y,v[x][i].y});
			}
		}
	}
	if(ans==2e9)return 0;
	else return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int nx=0;
		cin>>nx;
		cin>>t[i][nx];
		for(int j=2;j<=k[i];j++){
			int x=0;
			cin>>x;
			cin>>t[i][x];
			v[nx].push_back({x,i});	
			v[x].push_back({nx,i});	
			nx=x;
		}
	}
	while(q--){
		cin>>l>>r;
		cout<<(bfs()+a[l]+a[r])<<endl;
	}
	return 0;
}
