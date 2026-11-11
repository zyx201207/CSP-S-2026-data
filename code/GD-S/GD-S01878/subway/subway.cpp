#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ll c=0;//测试点编号 
	ll n=0;//地铁线路数 
	ll m=0;//地铁站数 
	ll d=0;//每个地铁站最多被几条线路经过 
	ll q=0;//出行计划数 
	cin>>c>>n>>m>>d>>q;
	vector<ll> w(m,0);//从每个地铁站的地铁口走到站厅需要的时间 
	for(int i=0;i<m;i++) cin>>w[i];
	vector<ll> k(n,0);//第 (i) 条线路经过的地铁站数 
	vector<vector<ll>> a(n);//地铁站  
	vector<vector<ll>> t(n);//站厅 -> 站台  
	for(int i=0;i<n;i++) {
		a[i].resize(k[i]);
		t[i].resize(k[i]);
		for(int j=0;j<k[i];j++) {
			cin>>a[i][j]>>t[i][j];
		}
	}
	vector<ll> x(q,0),y(q,0);
	for(int j=0;j<q;j++) {
		cin>>x[j]>>y[j];
		cout<<w[x[j]]+w[y[j]]+a[i]*3<<"\n";
	}
	return 0;
}
