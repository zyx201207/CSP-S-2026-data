#include <bits/stdc++.h>
using namespace std;
int c,T,n,d;
vector<int> g[5005];
long long w[500005],y[500005],z[500005],flag[500005];
void dfs(int x,int ans) {
	if(ans>y[x]) return;
	if(ans<y[x]) {
		y[x] = ans;
		z[x] = 1;
	}else if(ans == y[x]) {
		z[x]++;
	}
	for(int i = 0;i<g[x].size();i++) {
		if(flag[x]!=3) {
			flag[x]++;
			dfs(g[x][i],ans+1);
			flag[x]--;
		}
	}
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--) {
		memset(z,0,sizeof(z));
		for(int i = 1;i<=5005;i++) g[i].clear();
		cin>>n>>d;
		for(int i = 1;i<=500005;i++) y[i] = n;
		for(int i = 1;i<=n;i++) {
			cin>>w[i];
		}
		for(int i = 1;i<=n;i++) {
			for(int j = 1;j<=n;j++) {
				if(abs(w[i]-w[j])<=d) {
					g[i].push_back(j);
					g[j].push_back(i);
				}
			}
		}
		dfs(1,0);
		int aans = 0;
		for(int i = 1;i<=n;i++) {
			if(z[i] == 2) aans++;
		}
		cout<<aans<<endl;
	}
	return 0;
}
