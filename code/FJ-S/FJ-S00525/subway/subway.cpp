#include<bits/stdc++.h>
using namespace std;
struct node{
	int id;
	int t;
};
struct nod{
	int p;
	long long step;
};
char c;
int n,m,d,r,w[500005];
vector<node>ve[505];
vector<node>mp[500005];
long long ans = 1e12;
void bfs(int x,int y){
	ans = 1e12;
	queue<nod>q;
	int vis[500005];
	q.push({x,0});
	vis[x] = 1;
	while(!q.empty()){
		nod t = q.front();
		q.pop();
		if(t.p==y)ans = min(t.step,ans);
		for(int i = 0;i<mp[t.p].size();i++){
			if(!vis[i]){
				int p1;
				for(int j = 0;j<mp[mp[t.p][i].id].size();j++){
					if(mp[mp[t.p][i].id][j].id==t.p){
						p1 = j;
					}
				}
				vis[i] = 1;
				q.push({mp[t.p][i].id,t.step+mp[t.p][i].t+mp[mp[t.p][i].id][p1].t});
			}
		}
	}
}
int main(){
	//freopen("subway.in",r,stdin);
	//freopen("subway.out",w,stdout);
	cin >> c >> n >> m >> d >> r;
	for(int i = 1;i<=m;i++){
		cin >> w[i];
	}
	for(int i = 1;i<=n;i++){
		int k;
		cin >> k;
		for(int j = 1;j<=k;j++){
			int x,y;
			cin >> x >> y;
			ve[i].push_back({x,y});
		}
		for(int j = 1;j<=k;j++){
			for(int l = 1;l<=k;l++){
				if(l!=j){
					mp[ve[i][j].id].push_back({ve[i][l].id,ve[i][j].t});
				}
			}
		}
	}
	for(int i = 1;i<=r;i++){
		int x,y;
		cin >> x>> y;
		bfs(x,y);
		cout << ans+w[x]+w[y]<<endl;
	}
	return 0;
}
