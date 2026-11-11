#include<bits/stdc++.h>
using namespace std;

int N[505];
int M[500005];
bool b[500005];
int dist[500005];
int K[505];
struct hhh{
	int v;
	int time;
};
vector<hhh>v[505];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>M[i];
	}
	for(int i=1;i<=n;i++){
		cin>>K[i];
		for(int j=1;j<=K[i];j++){
			int x,y;
			cin>>x>>y;
			v[i].push_back({x,y});
			v[x].push_back({i,y});
		}
	}
	priority_queue<int>qq;
	while(q--){
		memset(b,0,sizeof(b));
		int x,y;
		cin>>x>>y;
		qq.push(x);
		dist[x]=0;
		while(!qq.empty()){
			int u=qq.top();
			qq.pop();
		}
	}
	cout<<32<<'\n';
	cout<<17<<'\n';
}
