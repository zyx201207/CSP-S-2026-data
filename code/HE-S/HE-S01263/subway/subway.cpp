#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+9;
long long ti[maxn];
long long mins=0X3fffff;
long long x,y;
long long f[maxn];
struct node{
	long long id,tl;
};
vector<node>road [505];
void dfs(long long x,long long s){
	if(x==y){
		mins=min(mins,s);
		return ;
	}
	if(f[x]==1)return ;
	f[x]=1;
	for(int i=0;i<road[x].size();i++){
		dfs(road[x][i].id,s+road[x][i].tl);
	}
	f[x]=0;  
	return ;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >>ti[i];
	}
	for(long long i=1;i<=n;i++){
		int k;cin >> k;
		for(int j=1;j<=k;j++){
			long long u,v;
			cin >> u>>v;
			road[m+i].push_back({u,v});
			road[u].push_back({(m+i),v});
		}
	}
	while(q--){
		cin >> x >> y;
		dfs(x,ti[x]+ti[y]);
		cout <<mins<<endl;
	}
	return 0;
}



