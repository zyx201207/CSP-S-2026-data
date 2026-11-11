#include <bits/stdc++.h>
using namespace std;
int n,m;
long long q=0;
int ans = 0;
long long v[200001] = {};
int w[200001] = {};
void dfs(int a,int b){
	if (b == 0){
		if (a > ans){
			ans = a;
			return;
		}
		return;
	}
	else if (b == m){
		for (int i = 0;i < n;i++){
			q = v[i];
			long long g = q;
			w[i] = 1;
			dfs(q,b-1);
			q = g;
		}
	}
	else {
		for (int i = 0;i < n;i++){
			if (w[i] == 0){
				long long g = q;
				q = (q & v[i]);
				w[i] = 1;
				dfs(q,b-1);
				q = g;
				w[i]=0;
			}
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 0;i < n;i++){
		cin >> v[i];
	}
	sort(v,v+n);
	if (m == 1){
		cout << v[n-1];
	}
	else{
		dfs(q,m);
		cout << ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
