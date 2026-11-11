#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long n,m,a[N],maxn = -1;
bool mark[N];
void dfs(int x,long long ans){
	if(x >= m){
		maxn = max(maxn,ans);
		cout << ans << endl;
		return;
	}
	for(int i=1;i <= n;i++){
		if(mark[i] == 0){
			mark[i] = 1;
			dfs(x + 1,ans &= a[i]);
			mark[i] = 0;
		}
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i <= n;i++) cin >> a[i];
	if(m == 1){
		for(int i=1;i <= n;i++){
			maxn = max(maxn,a[i]);
		}
		cout << maxn;
		return 0;
	}
//	else{
//		for(int i=1;i <= n;i++){
//			long long ans = 1;
//			ans &= a[i];
//			for(int j=i;j <= n;j++){
//				long long sum = (ans & a[j]);
//				maxn = max(maxn,sum);
//				
//			}
//		}
//	}
	dfs(0,1);
	cout << maxn;
	return 0;
} 
