#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int N = 2e6 + 5,INF = 0x3f3f3f3f;

bool bst;
int n,d;
int a[N];
int pre[N],nxt[N];
//能唯一抵达 i 且 不能以相同步数抵达 i + 1 的方案数. 
int f[N],g[N],minn1[N],maxn1[N],minn2[N],maxn2[N];
int num1[N],num2[N];
int lst1[N],lst2[N];
void solve(){
	cin >> n >> d;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i <= n;i++) 
		minn1[i] = minn2[i] = n + 1,maxn1[i] = maxn2[i] = 0,f[i] = g[i] = lst1[i] = lst2[i] = 0;
	for (int i = 1,j = 1;i <= n;i++){
		while (j <= i && a[i] - a[j] > d) j++;
		pre[i] = j;
		if (i != j && i != j + 1) minn2[j] = min(minn2[j],i),maxn2[j] = max(maxn2[j],i);
		if (i == j + 1) lst2[i - 1] = 1;
	}
	for (int i = n,j = n;i >= 1;i--){
		while (j >= i && a[j] - a[i] > d) j--;
		nxt[i] = j;
		if (i != j && i != j - 1) minn1[j] = min(minn1[j],i),maxn1[j] = max(maxn1[j],i);
		if (i == j - 1) lst1[i + 1] = 1;
	}
	num1[0] = lst1[0] = num2[n + 1] = lst2[n + 1] = 0;
	for (int i = 1;i < n;i++){
		if (maxn1[i] == 0 || i == 1) f[i] = 0;
		else if (pre[i] == pre[i - 1]) f[i] = maxn1[i] - minn1[i] + 1 + f[pre[i]] + lst1[minn1[i]];
		else f[i] = maxn1[i] - minn1[i] + 1;
		if (lst1[i]) lst1[i] = lst1[i - 1] + lst1[i];
//		cerr << i << " " << pre[i] << " " << nxt[i] << " " << maxn1[i] << " " << minn1[i] << " " << f[pre[i]] << " " << lst1[minn1[i]] << "\n";
	}
	for (int i = n;i >= 2;i--){
		if (maxn2[i] == 0 || i == n) g[i] = 0;
		else if (nxt[i + 1] == nxt[i]) g[i] = maxn2[i] - minn2[i] + 1 + g[nxt[i]] + lst2[maxn2[i]];
		else g[i] = maxn2[i] - minn2[i] + 1;
		if (lst2[i]) lst2[i] = lst2[i + 1] + lst2[i];
//		cerr << i << " " << maxn2[i] << " " << minn2[i] << " " << num2[i] << " " << g[i] << "\n";			
	}
//	for (int i = 1;i <= n;i++) cerr << i << " " << f[i] << " " << g[i] << "\n"; 
	int ans = 0;
	for (int i = 2;i < n;i++) ans += f[i] * g[i - 1];
	cout << ans << "\n";
}
bool bed;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int c,T;cin >> c >> T;while (T--) solve();
	return 0;
}
/*
0 1
12 49
7 21 33 44 68 74 88 89 109 110 129 191 

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 1
10 3
0 3 6 7 8 9 10 13 16 19

0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

*/
