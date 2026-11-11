#include<bits/stdc++.h>
using namespace std;
const int maxn=500010;
int c,n,m,d,q;
int t[maxn][600];
long long w[maxn];
struct road{
	int to,id;
};
vector<road> g[600];

bool p[600];
long long sum=0;
int idx;
long long dfs(int x,int y){
	if(x==y) return sum;
	for(int i=1;i<=g[x].size();i++){
		int v=g[x][i].to;
		if(p[v]==1) continue;
		sum+=w[v]+t[idx][v];
		if(idx!=g[x][i].id){
			sum+=t[idx][v]+t[g[x][i].id][v];
			idx=g[x][i].id;
		}
		dfs(v,y);
	}
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	long long k,a[2];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j%2]>>t[j][k];
			if(j%2==0) g[a[j%2+1]][j].to=a[j%2];
			else g[a[j%2-1]][j].to=a[j%2];
		}
	}
	int x,y;
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		sum=w[x];
		idx=g[x][1].id;
		cout<<dfs(x,y)<<endl;
	}
	return 0;
}
