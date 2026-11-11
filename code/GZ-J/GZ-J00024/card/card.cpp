//GZ-J00024 向子睿 云岩区实验中学
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Maxn = 500010, Maxm = 200010;
int n, m, a[Maxn], b[Maxm], len, cnt[Maxm], ind[Maxm];
unsigned long long rp = 0;
void solve(int x){
	len = 0;
	memset(ind, 0, sizeof(ind));
	for(int i = x; i <= n; i++){
		if(ind[a[i]]){
			for(int j = ind[a[i]] + 1; j <= len; j++)ind[b[j]] = 0;
			len = ind[a[i]];
		}else{
			b[++len] = a[i];
			ind[a[i]] = len;
		}
	}for(int i = 1; i <= len; i++){
		cnt[b[i]]++;
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	rp--;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}for(int i = 1; i <= n; i++){
		solve(i);
	}for(int i = 1; i <= m; i++){
		cout << cnt[i] << ' ';
	}return 0;
}
