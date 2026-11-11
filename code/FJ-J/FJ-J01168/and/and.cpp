#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;

int a[N],ma,n;
int ys[N],js[N];
int cnt[5];

void dfs1(int k,int num,int ms) {
	if (ms==1) {
		ma=max(ma, num);
		return ;
	}
	ms--;
	for (int i=k+1;i<=n-ms+1;i++) {
		dfs1(i, num&a[i], ms);
	} 
	return ;
}

bool cmd(int a,int b) {
	return a>b;
}

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int f=1;
	// 带有0/1字符的树，满足左1右0，每次操作只需要深度搜索到第一个符合条件的子树*2^dfn即可
	int m;
	cin >> n >> m;
	for (int i=1;i<=n;i++) {
		cin >> a[i];
		if (a[i]>4) f=0;
		if (a[i]<4) cnt[i]++;
	}
	if (m==1) {
		int ma=0;
		for (int i=1;i<=n;i++) ma=max(ma,a[i]);
		cout << ma;
		return 0;
	} 
	if (m==2) {
		int ma=0;
		for (int i=1;i<=n;i++) {
			for (int j=i+1;j<=n;j++) {
				ma=max(ma, a[i]&a[j]);
			}
		}
		cout << ma;
		return 0;
	}
	if (m==n) {
		int ans=a[1];
		for (int i=2;i<=n;i++) {
			ans=ans&a[i];
		}
		cout << ans;
		return 0;
	}
	if (n<=20) {
		for (int i=1;i<=n-m+1;i++) {
			dfs1(i, a[i], m);
		}
		cout << ma;
		return 0;
	}
	if (m==n-1) {
		int ma=0;
		ys[0]=js[n+1]=(1<<25)-1;
		for (int i=1;i<=n;i++) {
			ys[i]=ys[i-1]&a[i];
		}
		for (int i=n;i>=1;i--) {
			js[i]=js[i+1]&a[i];
		}
		for (int i=1;i<=n;i++) {
			ma=max(ma, ys[i-1]&js[i+1]);
		} 
		cout << ma;
		return 0;
	}
	if (f) {
		sort(a+1,a+1+n,cmd);
		if (cnt[3]<=m) cout << 3;
		else if (cnt[3]+cnt[2]<=m) cout << 2;
		else if (cnt[3]+cnt[1]<=m) cout << 1;
		else cout << 0;
		return 0;
	}
	cout << 0;
	return 0; 
} 
