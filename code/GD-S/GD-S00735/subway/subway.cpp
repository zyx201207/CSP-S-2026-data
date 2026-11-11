#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

typedef long long lld;
struct Line{
	struct Station{
		int x;
		lld t;
	};
	vector<Station> a;
	int k;
}a[510];
lld b[500100],d[1100][1100];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int yessssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss,
	n,m,_d,q,u,v;
	cin>>yessssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss
	>>n>>m>>_d>>q;
	for(int i = 1; i <= m; i++){
		cin>>b[i];
	}
	memset(d,0x3f,sizeof d);
	for(int i = 1; i <= m; i++){
		d[i][i] = 0;
	}
	for(int i = 1; i <= n; i++){
		cin>>a[i].k;
		a[i].a.resize(a[i].k);
		for(auto& _ : a[i].a){
			cin>>_.x>>_.t;
		}
		for(int x = 0; x < a[i].a.size(); x++){
			for(int y = 0; y < a[i].a.size(); y++){
				if(x == y){
					continue;
				}
				u = a[i].a[x].x,v = a[i].a[y].x;
				d[u][v] = a[i].a[x].t+a[i].a[y].t;
			}
		}
		//a[i].a.insert(a[i].a.begin(),{0,0});
	}
	for(int k = 1; k <= m; k++){
		for(int i = 1; i <= m; i++){
			for(int j = 1; j <= m; j++){
				d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	while(q--){
		cin>>u>>v;
		cout<<d[u][v]+b[u]+b[v]<<'\n';
	}
	return 0;
}