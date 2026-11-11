#include<bits/stdc++.h>
using namespace std;
long long a[200024];
long long b[200024];
bool flag[200024];
long long n, m, maxn = 0;
void dfs(long long k, long long cnt){
	if (k > m){
		maxn = max(maxn, cnt);
		return ;
	}
	for (int i = 1; i <= n; i++){
		if (!flag[i]){
			flag[i] = 1;
			dfs(k + 1, cnt & a[i]);
			flag[i] = 0;
		}
	}
	return ;
}
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    bool flag1 = 1, flag2 = 1;
    for (int i = 1; i <= n; i++){
		cin >> a[i];
		if ((a[i] + 1) % 2 != 0){
			flag1 = 0;
		}
		if (a[i] != i - 1){
			flag2 = 0;
		}
	}
	if (flag1){
		long long ans = -1;
		maxn = 0;
		int x = 1;
		while (m--){
			for (int i = 1; i <= n; i++){
			     if (a[i] > maxn){
					 maxn = a[i];
					 x = i;
				 }
	    	}
	    	if (ans == -1){
				ans = maxn;
			}else{
				ans &= maxn;
			}
			a[x] = 0;
		}
		cout << ans << endl;
	}else if (flag2){
		cout << n - m << endl;
	}else{
		dfs(1, INT_MAX);
	    cout << maxn << endl;
	}
	
    return 0;
}
