#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
long long n,m,a[N],ans,f[N];
int vis[N];
void dfs(int x){
	if(x == m + 1){
		long long sum = f[1];
		for(int i = 2;i<=m;i++){
			sum &= f[i];
		}
		ans = max(ans,sum);
		return;
	}
	for(int i = 1;i<=n;i++){
		if(!vis[i]){
			f[x] = a[i];
			vis[i] = 1;
			dfs(x + 1);
			vis[i] = 0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(1);
	cout<<ans;
}
