#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
int k[505];
int a[505][500005];
int v[505][500005];
vector<int> vec[500005];
vector<int> station[500005];
int ans[500005];
bool vis[500005];
vector<int> G[500005];
void bfs(int beg){
	queue<pair<int,int>> q;
	q.push({beg,0});
	vis[beg]=1;
	ans[beg]=0;
	while(q.size()){
		int now=q.front().first;
		int need=q.front().second;
		q.pop();
		for(int i=0;i<G[now].size();i++){
			int nxt=G[now][i];
			if(vis[nxt]==0){
				ans[nxt]=need+1;
				q.push({nxt,need+1});
				vis[nxt]=1;
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	int same=-1e9;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=0;j<2*k[i];j++){
			if(j%2==0){
				cin>>a[i][j/2+1];
				vec[a[i][j/2+1]].push_back(i);
			}
			else{
				cin>>v[i][j/2+1];
				if(same==-1e9) same=v[i][j/2+1];
				else{
					if(same!=v[i][j/2+1]){
						flag=false;
					}
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(vec[i].size()){
			for(int l=0;l<vec[i].size();l++){
				for(int r=l+1;r<vec[i].size();r++){
					if(l==r) continue;
					G[vec[i][l]].push_back(vec[i][r]);//vec: two different root can be connected
					G[vec[i][r]].push_back(vec[i][l]);
				}
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int minn=1e9;
		for(int i=0;i<vec[x].size();i++){
			memset(vis,0,sizeof vis);
			memset(ans,0x3f,sizeof ans);
			bfs(vec[x][i]);
			for(int j=0;j<vec[y].size();j++){
				minn=min(minn,ans[vec[y][j]]);
			}
		}
		cout<<minn*same*2+w[x]+w[y]+2*same<<endl;
	}
	return 0;
}
