#include<bits/stdc++.h>
using namespace std;
long long f[510][510];
long long ww[500100];
int k[510];//路线节点数 
int c,n,m,d,q;
struct kkk{
	long long v,w;
};
vector<kkk> g[500100];
vector<long long>a[501],t[501];//节点 i 参与的路线 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i <= m;i++){
		cin>>ww[i];
	}
	for(int i = 1;i <= n;i++){
		cin>>k[i];
		for(int j = 1;j <= k[i];j++){
			int aa,tt;
			cin>>aa>>tt;
			a[i].push_back(aa);
			t[i].push_back(tt);
			g[aa].push_back({i,tt});
		} 
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			f[i][j] = 1e18;
		}
		f[i][i] = 0;
	}
	for(int i = 1;i <= m;i++){
		for(kkk v:g[i]){
			for(kkk w:g[i]){
				int vis1 = v.v,vis2 = w.v;
				if(vis1 == vis2)continue;
				f[vis1][vis2] = v.w+w.w;
				f[vis2][vis1] = v.w+w.w;
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			for(int k = 1;k <= n;k++){
				f[i][j] = min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	for(int i = 1;i <= q;i++){
		int st,ed;
		long long ans = 1e18;
		cin>>st>>ed;
		for(kkk v:g[st]){
			for(kkk w:g[ed]){
				int vis1 = v.v,vis2 = w.v;
				long long tmp = ww[st]+v.w+ f[vis1][vis2]+w.w+ ww[ed];
				ans = min(ans,tmp);
			}
		}
		cout<<ans<<endl;
	}
	return 0; 
} 
