#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,r;
int st,en;
vector<int> w,k;
vector<vector<int> > z;
int dis[510][5],vis[510][4];
ll bfs(int e,int u){
	queue<pair<int,int> > q;
	pair<int,int> g;g.first=e;g.second=u;
	q.push(g);
	dis[e][u]=0;
	while(q.empty()){
		pair<int,int> pck=q.front();q.pop();
		int x=pck.first,ce=pck.second;
		if(x==en){
			if(ce==2){
				return dis[x][2]+w[x];
			}
			if(ce==3){
				int mn=100010;
				for(int i=0;i<t;i++){
					for(int j=0;j<k[i];j+=2){
						if(z[i][j]==x){
							mn=min(mn,z[i][j+1]);
							break;
						}
					}
				}
				return dis[x][3]+w[x]+mn;
			}
		}
		if(ce==1){
			q.push({x,2});
			vis[x][2]=1;
			dis[x][2]=dis[x][3]+w[x];
		}else if(ce==2){
			for(int i=0;i<t;i++){
				for(int j=0;j<k[i];j+=2){
					if(z[i][j]==x){
						if(vis[z[i][j]]){
							
						}
					}
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0,sizeof(dis));
	memset(vis,0,sizeof(vis));
	int no;cin>>no>>t>>n>>no>>r;
	for(int i=0;i<n;i++){
		int p;cin>>p;
		w.push_back(p);
	}
	while(t--){
		vector<int> p;
		int d;cin>>d;
		k.push_back(d);
		for(int i=1;i<=n;i++){
			int ma,mb;cin>>ma>>mb;
			p.push_back(ma);
			p.push_back(mb);
		}
		z.push_back(p);
	}
	while(r--){
		cin>>st>>en;
		cout<<bfs(st,1)<<'\n';//bfs±©ËÑ 
	}
	return 0;
}
