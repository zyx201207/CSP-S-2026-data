#include <bits/stdc++.h>
using namespace std;
int n , k , a[500005] , ans[300005];
bool be[300005];
stack <int> stk;
int main (){
	freopen ("card.in" , "r" , stdin);
	freopen ("card.out" , "w" , stdout);
	cin >> n >> k;
	for (int i = 1 ; i <= n ; i++)  cin >> a[i];
	for (int i = 1 ; i <= n ; i++){
		for (int j = i ; j <= n ; j++){
			if (be[a[j]])
				while (stk.top () != a[j]){
					be[stk.top ()] = 0;
					stk.pop ();
				}
			else{
				be[a[j]] = 1;
				stk.push (a[j]);
			}
		}
		while (!stk.empty ()){
			ans[stk.top ()]++;
			stk.pop ();
		}
	}
	for (int i = 1 ; i <= k ; i++)  cout << ans[i] << " ";
	return 0;
}
