#include <bits/stdc++.h>
using namespace std;
int n, m, maxn = 0;
int a[200001];
bool vis[200001];
int x[200001];
void todo(){
	int ans = x[1]&x[2];
	for (int i = 3;i<=m;i++){
		ans = ans&x[i];
	}
	maxn = max(maxn, ans);
}

void dg(int deep){
	if(deep > m){
		todo();
		return ;
	}
	for (int i = 1;i<=n;i++){
		if(!vis[i]){
			vis[i] = 1;
			x[deep] = a[i];
			dg(deep+1);
			x[deep] = 0;
			vis[i] = 0;
		}
	}
}

int main(){

	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1;i<=n;i++){
		cin >> a[i];	
	}
	dg(1);
	cout << maxn;
	return 0;
}
