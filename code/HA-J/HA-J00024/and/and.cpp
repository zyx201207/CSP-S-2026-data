#include <bits/stdc++.h>                   
using namespace std;
long long n,m,a[300000],ans,ch[300000];
void dfs(long long k,long long x){
	if(k > n){
		long long s = a[ch[1]];
		for(int i = 2;i < k;i++){
			s &= a[ch[i]];
		}
		ans = max(ans,s);
	}
	for(int i = x + 1;i <= n;i++){
		ch[k] = i;
		dfs(k + 1,i);
	} 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	cin >> a[1];
	if(m == n || m == 1) ans = a[1];
	for(int i = 2;i <= n;i++){
		cin >> a[i];
		if(m == 1) ans = max(a[i],ans);
		if(m == n) ans &= a[i];
	}
	if(m == 1 || m == n){
		cout << ans;
		return 0;
	}
	dfs(0,0);
	cout << ans;
	return 0;
}
