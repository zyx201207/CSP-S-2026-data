#include <bits/stdc++.h>
using namespace std;
int n,m,maxx = -1,a[200005];
void dfs( int id,int cnt,int sum ){
	maxx = max(maxx,sum);
	if( id == n+1 ) return;
	if( cnt == m ) return;
	for( int i = id+1;i<=n;i++ ){
		dfs(i,cnt+1,sum&a[i]);
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for( int i = 1;i<=n;i++ ){
		cin >> a[i];
	}
	dfs(0,0,0);
	cout << maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
