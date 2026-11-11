//50 pts
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005],use[200005];
int ans = 0;
void dfs(int now,int cnt) {
	if (now==n+1) {
		if (cnt!=m) return;
		int s = -1;
		for (int i = 1;i<=n;i++)
			if (use[i])
				if (s==-1) s = a[i];
				else s = (s&a[i]);
		ans = max(s,ans);
		return;
	}
	use[now] = 0;
	dfs(now+1,cnt);
	use[now] = 1;
	dfs(now+1,cnt+1);
	use[now] = 0;
}
void solve1() {
	for (int i = 1;i<=n;i++) cin>>a[i];
	dfs(1,0);
	cout<<ans<<endl;
	exit(0);
}
void solve2() {
	for (int i = 1;i<=n;i++) {
		int a;
		cin>>a;
		ans = max(a,ans);
	}
	cout<<ans<<endl;
	exit(0);
}
void solve3() {
	for (int i = 1;i<=n;i++) cin>>a[i];
	for (int i = 1;i<=n;i++)
		for (int j = i+1;j<=n;j++)
			ans = max(ans,(a[i]&a[j]));
	cout<<ans<<endl;
	exit(0);
}
void solve4() {
	int a;
	cin>>a;
	ans = a;
	for (int i = 2;i<=n;i++) {
		int a;
		cin>>a;
		ans = (ans&a);
	}
	cout<<ans<<endl;
	exit(0); 
}
bool cmp(int a,int b) {
	return a>b;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	cin>>n>>m;
	if (n<=20) solve1();
	else if (m==1) solve2();
	else if (m==2) solve3();
	else if (m==n) solve4();
	for (int i = 1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp); 
	cout<<a[m]<<endl;
	return 0;
}
