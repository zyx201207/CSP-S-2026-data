#include<iostream>
#include<algorithm>
using namespace std;

typedef long long  ll;
ll n,m;
int a[(int)2e5+5];
bool vis[(int)2e5+5];

ll dfs(int p, int idx){
	if(idx==m){
		return a[p];
	}
	vis[p]=1;
	ll res = -0x3f3f3f3f3f3f3f3f;
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		res = max(res,a[p]&dfs(i,idx+1));
	}
	vis[p]=0;
	return res;
}

int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	cin >> n >> m;
	
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	
	sort(a+1,a+n+1,greater<int>());
	
	if(n==m){
		ll ans = a[1];
		for(int i=2;i<=n;i++){
			ans &= a[i];
		}
		cout << ans << endl;
		return 0;
	}
	if(m==1){
		cout << a[1] << endl;
		return 0;
	}
	if(m==2){
		ll ans = a[1]&a[2];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans = max(ans,(ll)a[i]&a[j]);
			}
		}
		cout << ans << endl;
		return 0;
	}
	
	ll ans = -0x3f3f3f3f3f3f3f3f;
	
	for(int i=1;i<=n;i++){
		ans = max(ans,dfs(i,1));
	}
	cout << ans << endl;
	return 0;
}
