#include<bits/stdc++.h>
using namespace std;
#define int long long //注意longlong内存

//多测清空
//取消fre注释
//检查格式，检查边界
//注意时空复杂度 

const int N = 5e5 + 5;
int a[N], ans[N], b[N], las[N];

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);//注意不混用cin,scanf,getchar
	
	int n, m, flaga = 1;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] < a[i - 1])
			flaga = 0;
	}
	if(flaga) {
		for(int i = 1; i <= n; i++)
			las[a[i]] = i;
		for(int i = 1; i <= m; i++)
			cout << las[i] << ' ';
		cout << endl;
		return 0;
	}
	if(m == 2) {
		for(int st = 1; st <= n; st++) {
			if(a[st] == 1 || a[n] == 1)
				ans[1]++;
			if(a[st] == 2 || a[n] == 2)
				ans[2]++;
		}
		cout << ans[1] << ' ' << ans[2] << endl;
		return 0;
	}
	int cur = 0;
	for(int st = 1; st <= n; st++) {
		cur = 0;
		for(int i = st; i <= n; i++) {
			for(int j = cur; j >= 1; j--) {
				if(b[j] == a[i]) {
					cur = j - 1;
					break;
				}
			}
			b[++cur] = a[i];
		}
		for(int i = 1; i <= cur; i++)
			ans[b[i]]++;
	}
	for(int i = 1; i <= m; i++)
		cout << ans[i] << ' ';
	
	return 0;
	//Trick or Treat!
	//I_AK_IOI
}

