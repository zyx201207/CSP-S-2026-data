#include <bits/stdc++.h>
using namespace std;

int n,m;
int js = 0;
int a[200005] = {};
int vis[200005] = {};

void dfs(int x,int js1){
	if (x == m){
		js = max(js,js1);
		//cout << js1 << " " << js << endl;
		return;
	}
	for (int i = 1; i <= n; i++){
		if (vis[i]){
			continue;
		}
		vis[i] = 1;
		dfs(x+1,a[i] & js1);
		vis[i] = 0;
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	for (int i = 1; i <= n; i++){
		vis[i] = 1;
		dfs(1,a[i]);
		vis[i] = 0;
	}
	cout << js;
	
	return 0;
}
