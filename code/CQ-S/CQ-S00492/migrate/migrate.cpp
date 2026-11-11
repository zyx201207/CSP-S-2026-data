#include <bits/stdc++.h>
#define int long long 
#define maxn 2000005
using namespace std;
bool st;
int x,T,n,m,d,a[maxn],to[maxn][21],pre[maxn];
int answer(int l,int r){
	if (pre[r-1]-pre[l-1]) return 0;
	int sum = 0;
	for (int i = to[l][0];i < r;i = to[i][0]){
		sum += to[i-1][0] == to[i][0] || r <= to[i-1][0];
		if (i-2) sum += to[i-2][0] == to[i][0] || r <= to[i-2][0];
//		int t = r;
//		for (int j = 20;~j;j--){
//			if (lst[t][j] > i) t = lst[t][j]; 
//		}
//		t = lst[t][0];
//		sum += i-t;
	}
	return sum;
}
bool en;
signed main(){
	#ifndef LOCAL
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	#endif
	cerr << (&en-&st)/1048576.0 << "\n";
	cin >> x >> T;
	while (T--){
		cin >> n >> d;
		for (int i = 1;i <= n;i++) cin >> a[i];
		for (int i = n,j = n;i;i--){
			while (a[j]-a[i] > d) j--;
			to[i][0] = j,pre[i] = to[i][0] == i;
			for (int j = 1;j <= 20;j++) to[i][j] = to[to[i][j-1]][j-1];
		}
		for (int i = 1;i <= n;i++) pre[i] += pre[i-1];
		int cnt = 0;
		for (int i = 1;i <= n;i++)
			for (int j = i;j <= n;j++)
				cnt += answer(i,j) == 1;
		cout << cnt << "\n";
	}
	cerr << clock() << "\n";
	return 0;
}
