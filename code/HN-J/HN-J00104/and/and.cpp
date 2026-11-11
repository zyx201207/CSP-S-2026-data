#include<bits/stdc++.h>
using namespace std;
long long n, m, cnt;
int a[200005];
int dfs(int maxx){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			maxx = max((a[j] & a[i]), (maxx & a[i]));
		}
	}
	if(cnt <= m){
		cnt++;
		dfs(maxx);
	}
	else{
		return maxx;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	cout << (dfs(1));
	return 0;
}
