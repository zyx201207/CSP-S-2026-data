#include<bits/stdc++.h>
using namespace std;
struct as{
	int u;
	int v;
};
int ans;
int x,y;
int c,n,m,d,q;
int w[1000001];
vector<as> ss[100001];
int bll[1000001];
void dfs(int u,int abc){
//	cout << u << "   " << abc;
	if(u == y){
//		cout << "     " << abc + w[u];
		ans = min(ans,abc + w[u]);
		return;
	}
	for(int i = 0;i < ss[u].size();i++){
		if(bll[ss[u][i].u] == 0){
			bll[ss[u][i].u] = 1;
//			cout << " + " << ss[u][i].v << "   " << u << " >> " << ss[u][i].u << endl;
			dfs(ss[u][i].u,ss[u][i].v + abc);
			bll[ss[u][i].u] = 0;
		}
	}
	return;
}
int main(){
	freopen("subway3.in","r",stdin);
	freopen("subway.out","w",stdout);	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		int u;
		int a[10001],b[10001];
		cin >> u;
		for(int i = 1;i <= u;i++){
			cin >> a[i] >> b[i];
		}
		for(int i = 1;i <= u;i++){
			for(int j = 1;j <= u;j++){
				if(j != i){
					ss[a[i]].push_back({a[j],b[i] + b[j]});
					ss[a[j]].push_back({a[i],b[i] + b[j]});
				}
			}
		}
	}
	for(int i = 0;i < q;i++){
		ans = 1000001;
		cin >> x >> y;
		bll[x] = 1;
//		cout << x << y;
		dfs(x,w[x]);
		cout << ans << endl;
	}
}
