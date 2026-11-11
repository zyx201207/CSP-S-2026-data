#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010];
long long s[200010];
long long vis[200010];
long long ans,cnt;
//(a & b) 
void dfs(int d){
	if(d > m){
		cnt = s[1];
		for(int i = 2;i <= m;i++){
			cnt = (cnt & s[i]);
		}
		ans = max(ans,cnt);
		return;
	}
	for(int i = 1;i <= n;i++){
		if(vis[i] == 0){
			vis[i] = 1;
			s[d] = a[i];
			dfs(d + 1);
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
	dfs(1);
	cout << ans ;
	return 0;
}
