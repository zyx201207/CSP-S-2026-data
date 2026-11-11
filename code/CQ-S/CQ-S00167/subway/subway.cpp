#include<bits/stdc++.h>
using namespace std;

struct node{
	int p,t,id;
};

int c,n,m,d,q;
long long w[500005];
int k[505];
vector<node> v[500005],g[500005];
bool f[500005];
int a[505][20005];
int t[505][20005];

long long dfs(int x,int y){
	if(x==y) return 0;
	long long ans=INT_MAX;
	while(g[x].size()){
		int h=g[x][g[x].size()-1].p;
		long long l=g[x][g[x].size()-1].t;
		int i=g[x][g[x].size()-1].id;
		g[x].pop_back();
		if(!f[x]){
			f[x]=1;
			ans=min(t[i][x]+dfs(h,y)+l,ans);
			f[x]=0;
		}
	}
	return ans;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++) cin >> w[i];
	for(int i=1;i<=n;i++){
		cin >> k[i];
		for(int j=1;j<=k[i];j++){
			cin >> a[i][j] >> t[i][j];
			if(j==1) continue;
			else{
				v[a[i][j]].push_back({a[i][j-1],t[i][j-1],i});
				v[a[i][j-1]].push_back({a[i][j],t[i][j],i});
			}
		}
	}
	while(q--){
		for(int i=0;i<m;i++) g[i]=v[i];
		memset(f,0,sizeof f);
		int x,y;
		cin >> x >> y;
		cout << w[x]+dfs(x,y)+w[y] << endl;
	}
	return 0;
}
