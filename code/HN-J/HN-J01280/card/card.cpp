#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5, M = 3e5 + 5;
int n, m, a[N], ans[M], pre[M];
vector<int> v;
signed main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	bool flag = 1;
	for(int i = 1; i <= n; i++) flag &= (a[i] >= a[i - 1]);
	if(flag && n >= 5000){
		for(int i = 1; i <= n; i++)
			ans[a[i]] = i;
		for(int i = 1; i <= m; i++) cout << ans[i] << ' ';
		return 0;
	}
	for(int i = 1; i <= n; i++){
		v.clear();
		for(int j = 1; j <= m; j++) pre[j] = -1;
		for(int j = i; j <= n; j++){
			if(pre[a[j]] != -1){
				while(1){
					int pos = v.back();
					v.pop_back();
					if(pos == pre[a[j]]) break;
					pre[a[pos]] = -1;
				}
			}
			pre[a[j]] = j;
			v.emplace_back(j);
		}
		for(int pos : v){
			ans[a[pos]]++;
//			cout << i << ' ' << pos << ' ' << a[pos] << '\n';
		}
//		cout << '\n';
	}
	for(int i = 1; i <= m; i++) cout << ans[i] << ' ';
	return 0;
}
/*
woc我T4不会是不是废了

那我-S岂不是没救了 

无法AK之人

先想想^2

n^2应该不难 

不对啊，为啥会没有DP

这题不会是DP吧

计数？！ 

4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1

n^2实际上就是模拟，考虑怎么搞到m^2 

 考虑两端删除区间之间的关系 
 
 今年最后一题应该不是绿吧，感觉有青，不是咋这么难 
 
 loser 
*/ 
