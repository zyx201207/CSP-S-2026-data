#include<bits/stdc++.h>
#define fs first
#define sc second
#define N 500005
//#define int long long
using namespace std;

int n, m;
int a[N], nxt[N], lst[N], ans[N];

signed main(){
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		nxt[i] = n + 1;
		cin >> a[i];
		if(lst[a[i]]) nxt[lst[a[i]]] = i;
		lst[a[i]] = i;
	}
	
	nxt[n + 1] = n + 1;
	for(int i = n;i >= 1;i--) if(nxt[nxt[i]] != n + 1) nxt[i] = nxt[nxt[i]];
	
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			ans[a[j]]++;
			if(nxt[j] <= n) j = nxt[j];
		}
	}
	
	for(int i = 1;i <= m;i++) cout << ans[i] << " \n"[i == m];
	
	return 0;
	
} 
