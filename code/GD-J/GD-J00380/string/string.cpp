#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[200010];
char c[200010];
int tot = 0;
void op1(){
	if(tot % 2 == 1){
		int ttt = 0, tot1 = tot / 2;
		for(int i = 1; i <= n; ++i){
			ttt += a[i];
			if(ttt == tot1 && a[i+1] == 1){
				--n;
				for(int j = i+1; j <= n+1; ++j){
					a[j] = a[j+1];
					c[j] = c[j+1];
				}
				--tot;
				return;
			}else if(ttt > tot1){
				a[i]--;
				tot--;
				return;
			}
		}
	}
}
void op2(){
	tot /= 2;
	int ttt = 0, fro1 = 0;
	bool flg = 0;
	char fro2;
	for(int i = 1; i <= n; ++i){
		ttt += a[i];
		if(ttt == tot) break;
		if(ttt > tot && !flg){
			a[i] -= ttt-tot;
			fro1 = ttt-tot;
			fro2 = c[i];
			flg = 1;
			++i;
			++n;
		}
		if(flg){
			swap(fro1, a[i]);
			swap(fro2, c[i]);
		}
	}
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> a[i] >> c[i];
		tot += a[i];
	}
	op1();
	op2();
	//for(int i = 1; i <= n; ++i) cout << a[i] << " " << c[i] << "\n";
	int ans = 0;
	for(int i = 1, j = n; i < j;){
		if(a[i] > a[j]){
			int sum = a[j];
			while(sum <= a[i]){
				if(c[i] != c[j]) ans += a[j];
				--j;
				sum += a[j];
			}
			if(sum == a[i]){
				--j;
			}else{
				if(c[i] != c[j]) ans += a[i]-(sum-a[j]);
				a[j] -= a[i]-(sum-a[j]);
			}
			++i;
		}else if(a[i] == a[j]){
			if(c[i] != c[j]) ans += a[i];
			++i;
			--j;
		}else{
			int sum = a[i];
			while(sum <= a[j]){
				if(c[i] != c[j]) ans += a[i];
				++i;
				sum += a[i];
			}
			if(sum == a[j]){
				++i;
			}else{
				if(c[i] != c[j]) ans += a[j]-(sum-a[i]);
				a[i] -= a[j]-(sum-a[i]);
			}
			--j;
		}
	}
	cout << ans;
	return 0;
}
