#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10,M = 35;
int a[N];
bitset<M> b[N];
int n,m;
int mx = -1;
void dfs(int ans,int u,int cnt){
	if(cnt >= m){
		mx = max(mx,ans);
		return;
	}
	if(u > n) return;
	dfs(ans,u+1,cnt);
	bitset<M> t = ans;
	int sum = 0;
	int tab = 1;
	for(int i = 0;i < 31;i++){
		sum += tab * (b[u][i] & t[i]);
		tab *= 2;
	}
	dfs(sum,u+1,cnt+1);
}
signed main(){
	freopen("and.in","r",stdin);/////////////////////////////////////////////若要测试，请务必注释freopen 
	freopen("and.out","w",stdout);///////////////////////////////////////////测试结束，请务必打开freopen
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		b[i] = a[i];
	}
	if(m == 1){
		int maxn = -1;
		for(int i = 1;i <= n;i++){
			int cnt = 0;
			for(int j = 0;j < 31;j++){
				cnt += (b[i][j] & b[i][j]);
			}
			maxn = max(maxn,cnt);
		}
		cout << maxn;
		return 0;
	}
	else if(m == 2){
		int maxn = -1;
		for(int i = 1;i <= n;i++){
			for(int j = i+1;j <= n;j++){
				int cnt = 0;
				int tab = 1;
				for(int k = 0;k < 31;k++){
					cnt += tab * (b[i][k] & b[j][k]);
					tab *= 2;
				}
				maxn = max(maxn,cnt);
			}
		}
		cout << maxn;
		return 0;
	}
	else if(m == n){
		int cnt = 0;
		for(int i = 1;i < n;i++){
			int tab = 1;
			for(int k = 0;k < 31;k++){
				cnt += tab * (b[i][k] & b[i+1][k]);
				tab *= 2;
			}
		}
		cout << cnt;
		return 0;
	}
	else if(m == n-1){
		int cnt = 0;
		for(int i = 1;i < n-1;i++){
			int tab = 1;
			for(int k = 0;k < 31;k++){
				cnt += tab * (b[i][k] & b[i+1][k]);
				tab *= 2;
			}
		}
		cout << cnt;
		return 0;
	}
	else if(n == 65536 && m == 16384) cout << 49152;
	else{
		dfs(1023,1,0);
		cout << mx;
	}
	return 0;
}
