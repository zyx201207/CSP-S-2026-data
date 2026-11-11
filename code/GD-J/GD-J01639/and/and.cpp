#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10;
int n, m, a[N], T;
int vis[N];
vector<int> g[35];
int tot[35], ans;
void erase(int x){
	for(int i=30;i>=0;i--){
		if((x>>i)&1) tot[i]--;
	}
}
void add(int x){
	for(int i=30;i>=0;i--){
		if((x>>i)&1) tot[i]++;
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("add.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		for(int j=30;j>=0;j--){
			if((a[i]>>j)&1) g[j].push_back(i), tot[j]++;
		}
	}
	for(int k=30;k>=0;k--){
		if(tot[k] >= m){
			ans += (1<<k);
			for(int p=0;p<=30;p++) tot[p]=0;
			T++;
			for(int x:g[k]) {
				if(vis[x]==T-1){
					vis[x] = T;
					add(a[x]);
				}
			}
		}
		
	}
	cout << ans << '\n';
	return 0;
}
