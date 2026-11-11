#include <bits/stdc++.h>
using namespace std;
int sb,n,m,d,q,w[500005],k[505],a[505][500005],t[505][500005],c[500005],
x[100001],y[100001],o = 500005,ans[100001],f[500005],cost;
vector <int> e[500005];
void change(){
	memset(ans,0,sizeof(ans));
	for(int i = 1;i <= o;i++)
		ans[i] = f[i];
}
void dfs(int fa,int u,int y,int sum){
	if(u == y){
		if(o > sum){
			o = sum;
			change();
		}
		return;
	}
	for(int i = 0;i < e[u].size();i++){
		if(e[u][i] != fa){
			f[sum + 1] = e[u][i];
			dfs(u,e[u][i],y,sum + 1);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> sb >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)
		cin >> w[i];
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		for(int j = 1;j <= k[i];j++){
			cin >> a[i][j] >> t[i][j];
			c[a[i][j]] = i;
			if(j > 1){
				e[a[i][j - 1]].push_back(a[i][j]);
				e[a[i][j]].push_back(a[i][j - 1]);
			}
		}
	}
	for(int i = 1;i <= q;i++)
		cin >> x[i] >> y[i];
	if(n == 2)
		for(int i = 1;i <= q;i++){
			dfs(0,x[i],y[i],0);
			cost = w[x[i]] + t[ans[1]][c[x[i]]] + t[ans[o]][c[y[i]]] + w[y[i]];
			for(int j = 1;j <= o;j++)
				if(c[ans[j]] != c[ans[j - 1]])
					cost += t[c[ans[j - 1]]][ans[j - 1]] + t[c[ans[j]]][ans[j]];
			cout << cost << endl;
		}
	else
		cout << "CCF I hate you!\n";
	return 0;
} 
