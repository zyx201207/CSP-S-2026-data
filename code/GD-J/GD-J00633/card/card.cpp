#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,m,a[500001],id[300001],ans[300001];
bool del[500002];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin >> n >> m;
	for (int i = 1;i <= n;++i){
		cin >> a[i];
	}
	for (int i = 1;i <= n;++i){
		memset(id,0,sizeof id);
		memset(del,0,sizeof del);
		for (int j = i;j <= n;++j){
			if (id[a[j]] && !del[id[a[j]]]){
				for (int k = id[a[j]];k < j;k++){
					del[k] = 1;
					if (id[a[k]] == k){
						id[a[k]] = 0;
					}
				}
			}
			id[a[j]] = j;
		}
		for (int j = i;j <= n;++j){
			if (!del[j]){
				ans[a[j]]++;
			}
		}
	}
	for (int i = 1;i <= m;++i){
		cout << ans[i] << ' ';
	}
	return 0;
} 
//O(n^3)，24（运气好能48）pts吧 
