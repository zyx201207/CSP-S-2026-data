#include<bits/stdc++.h>
using namespace std;
int a[2000050],n,m,id,d[2000050],ans;
void dfs(int f)
{
	if(id == m){
		int sum = d[1];
		for(int i=2;i<=m;i++){
			sum = sum & d[i];
		}
		ans = max(sum,ans);
		return;
	}
	if(f > n) return;
	for(int i=0;i<=1;i++){
		if(i){
			d[++id] = a[f];
			dfs(f+1);
			id--;
		}
		dfs(f+1);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	dfs(1);
	cout << ans;
	return 0;
}
