#include <bits/stdc++.h>
using namespace std;
long long maxn,a[200005],n,m;
bool f[200005];
bool cmp(long long x,long long y){
	return x>y;
}
void dfs(long long sum,long long i){
	if (sum <= maxn)return ;
	if (i > m){
		maxn = sum;
		return ;
	}
	for (int j = 1;j <= n;j ++){
		if (f[j])continue;
		f[j] = 1;
		dfs((sum&a[j]),i+1);
		f[j] = 0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	for (int i = 1;i <= n;i ++){
		f[i] = 1;
		dfs(a[i],2);
		f[i] = 0;
	}
	cout << maxn;
	return 0;
}
