#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxx;
void dfs(long long id,long long cnt,long long sum){
	if (cnt == m){
		maxx = max(maxx,sum);
		return ;
	}
	if (id > n){
		return ;
	}
	dfs(id + 1,cnt + 1,sum & a[id]);
	dfs(id + 1,cnt,sum);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (int i = 1; i <= n; i++){
		cin>>a[i];
	}
	dfs(1,0,(long long)(1 << 31) - 1);
	cout<<maxx<<'\n';
	return 0;
}
