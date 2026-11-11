#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5, M = 3e5 + 5;
int n, m, a[N], ans[M], las[M];
bool fl = 1;
signed main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		if (a[i] < a[i - 1])fl = 0;
	}
	if (fl){//A
		for (int i = 1;i <= n;i++){
			if (a[i] ^ a[i - 1] && a[i - 1])ans[a[i - 1]] = i - 1;
			ans[a[n]] = n; 
		} 
		for (int i = 1;i <= m;i++)cout << ans[i] << " ";
		return 0;
	}
	for (int i = 1;i <= n;i++){
//		cout << "---------------" << i << "\n";
		memset(las, 0, sizeof(int) * (m + 1));
		for (int j = i;j <= n;j++){
			if (las[a[j]]){
//				cout << "£¡" << a[j] << "" << las[a[j]] << " " << j - 1 << "\n"; 
				for (int k = las[a[j]];k < j;k++)las[a[k]] = 0;
				las[a[j]] = j;
			}else{
//				cout << a[j] << " " << i << "\n";
				las[a[j]] = j;
			}
		}
		for (int j = 1;j <= m;j++)if (las[j]){
//			cout << "#" << i << " " << j << "\n";
			ans[j]++;
		}
	}
	for (int i = 1;i <= m;i++)cout << ans[i] << " "; 
	return 0;
}
