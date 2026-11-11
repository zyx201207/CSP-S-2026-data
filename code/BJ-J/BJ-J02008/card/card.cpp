#include <bits/stdc++.h>
//#define int long long
using namespace std;
int n , m , a[500005] , ans[300005] , tmp[300005];
stack <int> s;
signed main(){
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			tmp[j] = false;
		}
		for(int j = i;j <= n;j++){
			if(tmp[a[j]]){
				while(!s.empty()&&s.top() != a[j]){
					tmp[s.top()] = false;
					s.pop();
				}
			}
			else{
				s.push(a[j]);
				tmp[a[j]] = true;
			}
		}
		while(!s.empty()){
			ans[s.top()]++;
			s.pop();
		}
	}
	for(int i = 1;i <= m;i++){
		cout << ans[i] << " ";
	}
	return 0;
}
