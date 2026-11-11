#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], ans[300005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in", "r", stdin); //记得解除！！ 
    freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i=1; i<=n; i++) cin >> a[i];
	for(int i=1; i<=n; i++){//每局游戏 
		vector <int> v;//桌面 
		v.push_back(-1); //占位  v[0]不计算   len = v.end() - v.begin() - 1 
		for(int j=i; j<=n; j++){//发牌 
			int x = a[j];
			bool f = 0;
			for(int k=1; k<=(v.end()-v.begin()-1); k++){
				if(f == 1){
					v[k] = 0;
				}
				if(v[k] == x){
					f = 1;
				}
			}
			if(f == 0) v.push_back(x);
		}
		for(int k=1; k<=(v.end()-v.begin()-1); k++){
			ans[v[k]]++;
		}
	}
	for(int i=1; i<=m; i++) cout << ans[i] << ' ';
	return 0; 
}
