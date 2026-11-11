#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	vector < ll > pow(35);
	pow[0] = 1;
	for(int i = 1;i <= 31;i++)pow[i] = pow[i - 1] << 1;
	vector < vector < bool > > u(n + 1,vector < bool > ( 32 ));
	vector < bool > vis(n + 1); 
	for(int i = 1;i <= n;i++){
		ll o;
		cin >> o;
		for(int j = 30;j >= 0;j--){
			if(o >= pow[j]){
				u[i][j] = 1;
				o -= pow[j];
			}
		}
	}
	ll ans = 0;
	for(int j = 30;j >= 0;j--){
		int cnt = 0;
		queue < int > q;
		for(int i = 1;i <= n;i++){
			if(vis[i] == 1)continue;
			if(u[i][j] == 1){
				cnt++;
				continue;
			}
			q.push(i);
		}
		if(cnt < m)continue;
		ans += pow[j];
		while(!q.empty()){
			vis[q.front()] = 1;
			q.pop();
		}
	}
	cout << ans;
	return 0;
}
