#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstdio>
using namespace std;
const int N = 200005;
int n, m, a[N], maxn;
void dfs(int ar, int nd, int tot){
	
	//cout << ar << ' ' << nd << ' ' << tot << "\n{";
	if(nd == 0){
		//cout << '[' << tot << ']';
		maxn = max(maxn, tot);
		//cout << 'g';
		return;
	}
	if(n-ar == nd){
		//cout << 'f';
		for(int i=ar; i<n; i++){
			tot &= a[i];
		}
		maxn = max(maxn, tot);
		return;
	}
	for(int i=ar; i <= n-nd; i++){
		dfs(i+1, nd-1, (tot & a[i]));
	}
	//cout << '}';
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	for(int i=0; i<n; i++){
		dfs(i+1, m-1, a[i]);
	}
	cout << maxn;
	return 0;
}
