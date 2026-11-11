#include<bits/stdc++.h>
using namespace std;

const int N = 200005;
long long a[N];
int n,m;
long long p[N];
bool vis[N];
long long ans = -1;

void dfs(int x){
	if(x == n + 1){
		long long ti = p[1];
		for(int i = 2;i <= m;i++){
			ti = ti & p[i];
		}
		ans = max(ti,ans);
		return ;
	}
	for(int i = 1;i <= n;i++){
		if(!vis[i]){
			vis[i] = 1;
			p[x] = a[i];
			dfs(x+1);
			vis[i] = 0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(m == 1){
		for(int i = 1;i <= n;i++){
			ans = max(ans,a[i]);
		}
	}else if(n == m){
		ans = a[1];
		for(int i = 2;i <= n;i++){
			ans = ans & a[i];
		}
	}else if(m == 2){
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				long long t = a[i] & a[j];
				ans = max(ans,t);
			}
		}
	}else{
		memset(vis,0,sizeof(vis));
		dfs(1);
	}
	cout << ans << endl;
	return 0;
}
