#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int n,m,mx;
int a[maxn],ans[maxn];
bool vis[maxn];

void dfs(int i){
	if(i == m + 1){
		int sum = a[ans[1]];
		for(int i = 2;i <= m;i++){
			sum = (sum & a[ans[i]]);
		}
		mx = max(sum,mx);
		return;
	}
	for(int j = ans[i - 1] + 1;j <= n;j++){
		vis[j] = 1;
		ans[i] = j;
		dfs(i + 1);
		vis[j] = 0;
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
	}
	dfs(1);
	printf("%d",mx);
}