#include<bits/stdc++.h>
using namespace std;

int n,c,t,k;
vector<int> g[12345];
int d[100];
unsigned dis[20][20];
void floyd() {	memset(dis,0xff,sizeof dis);for(int i = 0;i<n;++i,dis[i][i]=0)for(int j : g[i]) dis[i][j] = dis[j][i]  =1;
	for(int k = 1;k<=n;++k)
	for(int i = 1;i<=n;++i){unsigned t = dis[k][i];
	if(~t)for(int j = 1;j<=n;++j)if(~dis[k][j])if(dis[i][j] > (t+dis[k][j]))dis[i][j]=t+dis[k][j];
	}
}
bool check(int c) {int tmp(1);
	while(c -= (c&(-c))) ++tmp;
	return tmp == k;
}
int tmlrock(int c) {int ret = 0;
	for(int i = 1;i<=n;++i) {
		d[i] = INT_MAX;
		for(int j = 1;j<=n;++j) if(c & (1<<j)) 
			d[i] = min<unsigned>(dis[i][j],d[i]);
		ret = max(ret,d[i]);
//	cout<<c<<' '<<ret<<' '<<i<<' '<<dis[i][1]<<endl;
	}
	return ret;
}
void solve15() {
	int ans = INT_MAX;
	floyd();
	for(int i = 1;i<(1<<n);++i) if(check(i))
		ans = min(ans,tmlrock(i));
	cout<<ans<<endl;
}
void solve_7_8() {
	
}
int main() {
	freopen("hub1.in","r",stdin);
//	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>c>>t;
	while(t--) {
		cin>>n>>k;
		for(int i = 1;i<n;++i) {
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(c<=3)solve15();
	}
//cout<<"1\n2";
	return 0;
}

