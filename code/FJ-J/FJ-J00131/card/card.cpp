#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int n,m;
	cin >> n >> m;
	vector < int > u(n + 1);
	vector < int > mx(m + 1);
	vector < int > ans(m + 1);
	for(int i = 1;i <= n;i++){
		cin >> u[i];
		mx[u[i]] = i;
	}
	for(int i = 1;i <= n;i++){
		int p = i;
		while(p <= n){
			ans[u[p]]++;
			p = mx[u[p]] + 1;
		}
	}
	for(int i = 1;i <= m;i++){
		cout << ans[i] << " ";
	}
	return 0;
}
