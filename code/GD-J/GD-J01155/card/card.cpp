#include<iostream>
#include<vector>
using namespace std;
vector<int>ve[500010];
int a[500010], ans[300010], f[300010];
int dfs(int u){
	int sum=1;
	for(int v:ve[u])sum+=dfs(v);
	ans[a[u]]+=sum;
	return sum;
}
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++)scanf("%d", &a[i]);
	for(int i=n;i>=1;i--){
		f[a[i]]=max(f[a[i]], i);
		ve[f[a[i]]+1].push_back(i);
	}
	dfs(n+1);
	for(int i=1;i<=m;i++)printf("%d ", ans[i]);
	return 0;
} 
