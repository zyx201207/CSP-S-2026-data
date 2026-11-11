#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 5e5+5;
ll c,n,m,d,q,ans,sum=0x3f3f3f3f;
ll w[N],f[505][505];
ll u_cp,v_cp;
struct node{
	ll v,cost;
};
struct stu{
	ll p,cost;
};
vector<node> edge[N];
vector<stu> pos[N];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1; i<=m; i++){
		cin>>w[i];
	}
	for(int i = 1; i<=n; i++){
		ll k;
		cin>>k;
		for(int j = 1; j<=k; j++){
			ll v,cost;
			cin>>v>>cost;
			edge[i].push_back({v,cost});
			pos[v].push_back({i,cost});
		}
	}
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=n; j++){
			if(i == j){
				f[i][j] = 0;
				continue;
			}
			f[i][j] = 0x3f3f3f3f;
		}
	}
	for(int i = 1; i<=n; i++){
		for(int j = 0; j<edge[i].size(); j++){
			node now = edge[i][j];
			ll v=now.v,cost=now.cost;
			for(int o = 0; o<pos[v].size(); o++){
				stu nw = pos[v][o];
				ll p=nw.p,co=nw.cost;
				if(p == i) continue;
				f[i][p] = min(f[i][p],cost+co);
			}
		}
	}
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=n; j++){
			for(int o = 1; o<=n; o++){
				f[i][j] = min(f[i][j],f[i][o]+f[o][j]);
			}
		}
	}
	
	for(int i = 1; i<=q; i++){
		cin>>u_cp>>v_cp;
		ans = (w[u_cp]+w[v_cp]);
		for(int j = 0; j<pos[u_cp].size(); j++){
			stu now = pos[u_cp][j];
			for(int o = 0; o<pos[v_cp].size(); o++){
				stu nw = pos[v_cp][o];
				sum = min(sum,f[now.p][nw.p]+now.cost+nw.cost);
			}
		}
		cout<<ans+sum<<endl;
		sum = 0x3f3f3f3f;
	}
	return 0;
}
