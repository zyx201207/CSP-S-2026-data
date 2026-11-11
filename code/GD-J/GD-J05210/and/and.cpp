#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],mx,vis[200005];
void dfs(long long x,long long sum,long long cnt){
	if (!cnt){
		for (int i=1;i<=n;i++){
			vis[i]=1;
			dfs(0,a[i],1);
			vis[i]=0;
		}
	}
	if (x>n){
		if (cnt==m){
			mx=max(mx,sum);
		}
		return;
	}
	if (cnt==m){
		mx=max(mx,sum);
		return;
	}
	if (!vis[x+1]) dfs(x+1,sum&a[x+1],cnt+1);
	dfs(x+1,sum,cnt);
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	dfs(0,0,0);
	cout<<mx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
