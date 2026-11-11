#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e5+10;
int a[maxn],n,m,pre[maxn],back[maxn],res,b[maxn];
bool A=1,B=1; 
void dfs(int dep,int p,int k) {
	if(res >= p) return ;
	if(dep == n + 1){
		if(k==m)res=max(res,p);
		return ;
	}
	dfs(dep+1,p&a[dep],k+1);
	dfs(dep+1,p,k);
}
signed main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] >= 4) A=0;
		if((a[i]+1)&a[i]!=0) B=0;
	}
	if(n <= 20) { //25
		int MAX=0;
		for(int i = 0;i <= 31;i++) MAX+=1ll<<i;
		dfs(1,MAX,0);
		cout<<res;
		return 0;
	} 
	if(m == n) { //5
		int ans = a[1];
		for(int i = 2;i <= n;i++) ans = ans & a[i]; 
		cout<<ans;
		return 0;
	}
	if(m == n-1) { //10
		back[n] = a[n]; pre[1] = a[1];
		for(int i = 2;i <= n;i++) pre[i] = pre[i-1] & a[i];
		for(int i = n-1;i >= 1;i--) back[i] = back[i + 1] & a[i];
		int ans = max(pre[n-1],back[2]);
		for(int i = 2;i < n;i++) {
			ans = max(ans,pre[i-1] & back[i+1]);
		}cout<<ans;
		return 0;
	}
	if(m == 2) { //15
		int ans = 0;
		for(int i = 1;i <= n;i++) {
			for(int j = i + 1;j <= n;j++) {
				ans = max(ans,a[i]&a[j]);
			}
		}cout<<ans;
		return 0;
	}
	if(m == 1) { //5
		int ans = 0;
		for(int i = 1;i <= n;i++) {
			ans = max(ans,a[i]);
		}cout<<ans;
		return 0;
	}
	if(A || B) { //15
		sort(a+1,a+1+n,greater<int>());
		int ans = a[1];
		for(int i = 2;i <= m;i++) ans &= a[i];
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n,greater<int>());
	int ans = a[1];
	for(int i = 2;i <= m;i++) ans &= a[i];
	cout<<ans;
	return 0;
} 
