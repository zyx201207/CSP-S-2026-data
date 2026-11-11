#include <bits/stdc++.h>
using namespace std;
int n,m,ans,b,a[200005],c[200005];
void dfs(int step,int start){
	if (step > m){
		b = c[1];
		for (int i = 2;i <= m;i++ ){
			b = c[i] & b;}
		ans = max(ans,b);
		return;}
	for (int j = start;j <= n;j++){
		c[step] = a[j];
		dfs(step + 1,j + 1);}
	return;}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	dfs(1,1);
	cout << ans;
	return 0;}
