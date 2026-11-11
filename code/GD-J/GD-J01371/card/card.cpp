#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 5e5 + 5;
const int MAXM = 3e5 + 5;
int n, m, a[MAXN], v[MAXN], aa[MAXN], cnt[MAXM], cc[MAXM];
bool flag = 1;
//v[i]表示下一个出现a[i]的位置 
//aa[i]表示 
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] < a[i - 1])	flag = false;
	}	
	for(int i = n; i >= 1; i--){
		int x = a[i];
		v[i] = aa[x];
		aa[x] = i;
	}
	if(n <= 5000){
		for(int i = n; i >= 1; i--){	
			for(int j = i; j <= n; j++){
				while(v[j] != 0)	j = v[j];
				cnt[a[j]]++;
			}
		}		
		for(int i = 1; i <= m; i++)	cout << cnt[i] << " ";
		return 0;
	}else if(m <= 2){
		for(int i = n; i >= 1; i--){
			if(a[i] != a[n]){
				cnt[a[i]]++;
				cnt[a[n]]++;
			}else{
				cnt[a[n]]++;
			}
		}
		for(int i = 1; i <= m; i++)	cout << cnt[i] << " ";
		return 0;
	}else if(flag){
		for(int i = 1; i <= n; i++)	cnt[a[i]] = n;
		for(int i = 1; i <= m; i++){
			cc[i] = upper_bound(a + 1, a + 1 + n, i) - lower_bound(a + 1, a + 1 + n, i);
		}
		for(int i = m; i >= 1; i--){
			cc[i] += cc[i + 1];
		}
		int sum = 0;
		for(int i = m - 1; i >= 1; i--){
			cnt[i] -= cc[i + 1];
		}
		for(int i = 1; i <= m; i++)	cout << cnt[i] << " ";
		return 0;
	}


	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/

