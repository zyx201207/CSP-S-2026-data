#include<bits/stdc++.h>
using namespace std;

long long n, mat[200010], sum[200010], cnt, tot;
char c, lst, ch[200010];

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i ++){
		int x;
		cin >> x >> c;
		tot += x;
		if(c == lst){
			mat[cnt] += x;
		} else {
			mat[++cnt] = x;
			ch[cnt] = c;
			lst = c;
		}
	}
	n = cnt;
	int ans = 0;
	for(int i = 1; i <= n; i ++){
		sum[i] = sum[i-1] + mat[i];
	}
	for(int i = 1; i <= tot / 2; i ++){
		int l = lower_bound(sum, sum+1+n, i) - sum;
		int r = lower_bound(sum, sum+1+n, tot-i+1) - sum;
		if(ch[l] != ch[r]) ans ++;
	}
	cout << ans;
	return 0;
}
