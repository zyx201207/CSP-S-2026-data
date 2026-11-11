#include<bits/stdc++.h>
#define ll long long
#define N 500010

using namespace std;
int n, m, cnt;
int a[N], pos[N], ans[N], b[N], vis[N];
bool f;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		if(a[i] < a[i - 1]) f = true; 
	}
	if(!f){
		for(int i = 1; i <= n; ++i){
			if(a[i] != a[i + 1]) ans[a[i]] = i;
		}
			for(int i = 1; i <= m; ++i) cout << ans[i] << " ";
		
		return 0;
	}
	for(int i = 1; i <= n; ++i){
		cnt = 0;
		for(int j = i; j <= n; ++j){
			if(vis[a[j]] == i){
				for(int k = pos[a[j]] + 1; k <= cnt; ++k) vis[b[k]] = 0;
				cnt = pos[a[j]];
				continue;
			}
			b[++cnt] = a[j];
			vis[a[j]] = i; pos[a[j]] = cnt;
		}
		for(int j = 1; j <= cnt; ++j) ans[b[j]]++;
	}
	for(int i = 1; i <= m; ++i) cout << ans[i] << " ";
	
	return 0;
}
