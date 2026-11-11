#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5;
int a[N];
int n,m;
int mx = 0;
void dfs(int ab,int ac,int dep){
	if(dep == m){
		mx = max(ab,mx);
		return;
	}
	for(int j = ac + 1;j <= n;j++){
		int tmp = ab & a[j];
		dfs(tmp,j,dep + 1);
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 0;i < n;i++) cin>>a[i];
	sort(a,a + n);
	for(int i = 0;i <= n - m;i++) dfs(a[i],0,1);
	cout<<mx;
	return 0;
}
