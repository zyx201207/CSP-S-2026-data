#include <bits/stdc++.h>
using namespace std;

struct edge{
	int x;
	long long t;
	int num;
};

const int MAXN=500010;
int c,n,m,d,qnum,f[MAXN];
vector<edge> a[21*MAXN];
long long w[MAXN];
vector<edge> sub[510];
long long ans[21*MAXN];
bool inque[21*MAXN];
priority_queue<pair<long long,int>> q;

long long dij(int u,int v){
	for(int i=1;i<=21*n;i++){
		ans[i]=-1;
		inque[i]=0;
	}
	while(!q.empty()){
		q.pop();
	}
	q.push({0,u});
	inque[u]=1;
	while(!q.empty()){
		int nx=q.top().second;
		if(nx==v){
			break;
		}
		q.pop();
		for(int i=0;i<a[nx].size();i++){
			int ny=a[nx][i].x;
			if(ans[ny]==-1||ans[nx]+a[nx][i].t<ans[ny]){
				ans[ny]=ans[nx]+a[nx][i].t;
				if(!inque[ny]){
					q.push({ans[ny],ny});
					inque[ny]=1;
				}
			}
		}
	}
	return ans[v];
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>qnum;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		int sum;
		cin>>sum;
		for(int j=1;j<=sum;j++){
			int y,z,u,v;
			cin>>y>>z;
			f[y]++;
			v=21*(y-1)+f[y]+1;
			for(int prei=1;prei<i;prei++){
				for(int prej=0;prej<sub[prei].size();prej++){
					u=sub[prei][prej].x;
					if(u==y){
						a[sub[prei][prej].num].push_back({v,sub[prei][prej].t+z,0});
						a[v].push_back({sub[prei][prej].num,sub[prei][prej].t+z,0});
						break;
					}
				}
			}
			u=21*(y-1)+1;
			a[u].push_back({v,w[y]+z,0});
			a[v].push_back({u,w[y]+z,0});
			sub[i].push_back({y,z,v});
			if(j!=1){
				int prev=sub[i][sub[i].size()-2].num;
				a[prev].push_back({v,0,0});
				a[v].push_back({prev,0,0});
			}
		}
	}
	for(int i=1;i<=qnum;i++){
		int u,v;
		cin>>u>>v;
		u=21*(u-1)+1;
		v=21*(v-1)+1;
		cout<<dij(u,v)+1<<endl;
	}
	return 0;
}
