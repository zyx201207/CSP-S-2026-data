//Trick||Treat!
#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 100;
const int M = 3e5 + 100;

int n, m, a[N], last[M];
int fa[N], sz[N];
int ans[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin >> n >> m;
	for(int i(1); i <= n; i++){
		cin >> a[i];
		last[a[i]] = i; //记录 a[i] 最后一次出现的位置  
		sz[i] = 1;
	}
	
	for(int i(1); i <= n; i++){
		fa[i] = last[a[i]] + 1; //连边建树  
		sz[fa[i]] += sz[i];
		ans[a[i]] += sz[i];
	}
	for(int i(1); i <= m; i++){
		cout << ans[i];
		if(i != m) cout << ' ';
	}
	return 0;
}
