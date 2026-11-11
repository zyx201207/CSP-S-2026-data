#include <bits/stdc++.h>
using namespace std;
int n, m, tot = -1;
vector<int> a;
vector<int> gett;
bool logcheck(int a){
	double x = log2(a + 1);
	if(abs(round(x) - x) == 0) return 1;
	return 0;
}
void f(int deep){
	for (int i = gett[deep - 1] + 1; i <= n - m + deep; i++){\
		if(deep == 1){
			a.resize(n + 1), gett.resize(m, 0);
		}
		gett[deep] = i;
		if(deep < m) f(deep + 1);
		else{
			int ans = a[gett[1]];
			for (int i = 2; i <= m; i++){
				ans = ans & a[gett[i]];
			}
			tot = max(tot, ans);
		}
	}
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	bool logf = 1, minf = 1;
	cin >> n >> m;
	a.resize(n + 1), gett.resize(m, 0);
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		if(!logcheck(a[i])) logf = 0;
		if(a[i] >= 4) minf = 0;
	}
	if(logf){
		cerr << "13\n"; 
		sort(a.begin() + 1, a.begin() + n + 1, greater<>());
		cout << a[m];
	}else if(minf){
		cerr << "16,17\n";
		int f3 = 0, f2 = 0, f1 = 0;
		for (int i = 1; i <= n; i++){
			if(a[i] == 3) f3++;
			if(a[i] == 2) f2++;
			if(a[i] == 1) f1++;
		}
		if(f3 >= m) cout << 3;
		else if(f3 + f2 >= m) cout << 2;
		else if(f3 + f1 >= m) cout << 1;
		else cout << 0; 
	}else if(m == 1){
		cerr << "6\n";
		int ans = -1;
		for (int i = 1; i <= n; i++){
			ans = max(ans, a[i]);
		}
		cout << ans;
	}else if(m == n){
		cerr << "7\n"; 
		int ans = a[1];
		for (int i = 2; i <= n; i++){
			ans = ans & a[i];
		}
		cout << ans;
	}else if(m == 2){
		cerr << "8,9,10\n"; 
		int ans = -1;
		for (int i = 1; i < n; i++){
			for (int j = i + 1; j <= n; j++){
				int cmp = a[i] & a[j];
				ans = max(ans, cmp);
			}
		}
		cout << ans;
	}else{
		cerr << "others\n"; 
		for (int i = 1; i <= n; i++) cin >> a[i];
		f(1);
		cout << tot;
	}
	cout << '\n';
	return 0;
}

// 65pts£¿ 
