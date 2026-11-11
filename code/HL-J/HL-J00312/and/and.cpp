#include <bits/stdc++.h>
using namespace std;
int n,m;
int max1 = -1;
int a[1000000],v[1000000];
void dfs(int x,int s){
	if (x == m){
		max1 = max(max1,s);
		return;
	}
	if (x == 0){
		for (int i = 0;i < n;i++){
			v[i] = 1;
			dfs(1,a[i]);
			v[i] = 0;
		}
		return;
	}
	for(int i = 0;i < n;i++){
		if (v[i] == 0){
			v[i] = 1;
			dfs(x + 1,s & a[i]);
			v[i] = 0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 0;i < n;i++){
		cin >> a[i];
	}
	dfs(0,0);
	cout << max1;
}
