#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N=1e5+5;
long long a[N];
vector<int> G[N];
long long maxn=0;
void dfs(int u,long long sum,int cnt){
	if(cnt>m){
		return;
	}
	sum=sum&a[u];
	if(cnt==m){
		maxn=max(maxn,sum);
	}
	for(int v:G[u]){
		dfs(v,sum,cnt+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	for(int i=1; i<=n; i++){
		for(int j=i+1; j<=n; j++){
			G[i].push_back(j);
		}
	}
	for(int i=1; i<=n; i++){
		dfs(i,a[i],1);
	}
	cout << maxn;
	return 0;
}
