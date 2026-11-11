#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,n,m,d,q,we[500010],cnt,l[500010][30][2],len[500010],km[510],vis[500510];
struct S{
	int u,v;
};
vector<S> v1[500510];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>we[i];
	for(int i=1;i<=n;i++){
		cin>>km[i];
		for(int j=1;j<=km[i];j++){
			int a,t;
			cin>>a>>t;
			l[a][++len[a]][0] = i;
			l[a][len[a]][1] = t;
			v1[m+i].push_back({a,t});
			v1[a].push_back({m+i,t});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<len[i];j++){
			int x = v1[i][j].u;
			for(int k=0;k<km[x];k++){
				v1[i].push_back({v1[x][k].u,0});
				v1[x].push_back({i,0});
			}
		} 
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<km[i];j++){
			int x = v1[i+m][j].u,y = v1[i+m][j].v;
			for(int k=0;k<len[x];k++){
				v1[i].push_back({v1[x][k].u,y+v1[x][k].v});
				v1[x].push_back({i+m,y+v1[x][k].v});
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > dis;
		dis.push({0,x});
		for(int i=1;i<=n+m;i++){
			int a = dis.top().first,b = dis.top().second;
			dis.pop();
			if(vis[b])continue;
			vis[b] = true;
			if(b==y){
				cout<<a + we[x] + we[y]<<'\n';
				break;
			}
			int h;
			if(b<=m)h = len[b];
			else h = km[b-m];
			for(int j=0;j<h;j++){
				S c = v1[b][j];
				if(!vis[c.u]){
					dis.push({c.v + a,c.u});	
				}
			}
		}
	}
	return 0;
}
