#include <bits/stdc++.h> 
using namespace std;

int n;
long long m, ans;
long long v[500005];
long long dfs(int l, int r, long long num, long long g){
	if(g<0)return 0;
	else if(g==0||(l==0&&r==n+1)) return 1;
	if(num-v[l]>v[r]-num){
		g -= v[r]-num;
		return dfs(l, r+1, num, g)+1;
	}
	else if(num-v[l]<v[r]-num){
		g -= num-v[l];
		return dfs(l-1, r, num, g)+1;
	}
	else{
		return max(dfs(l-1, r, num, g-num+v[l]), dfs(l, r+1, num, g+num-v[r]))+1;
	}
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	v[0] = -1000000000005;
	for(int i=1;i<=n;i++){
		cin >> v[i];
	}
	v[n+1] = 1000000000005;
	sort(v+1, v+n+1);
	for(int i=1;i<=n;i++){
		ans = max(ans, dfs(i-1, i+1, v[i], m));
	}
	cout << ans;
	return 0;
}
