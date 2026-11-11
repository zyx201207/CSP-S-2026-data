#include <bits/stdc++.h>
using namespace std;
int n, m, a[500001];
long long ans[300001];
bool f[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++){
		stack<int>s;
		for(int j = i; j <= n; j++){
			if(f[a[j]]){
				while(s.top() != a[j]){
					f[s.top()] = false;
					s.pop();
				}
			}else{
				s.push(a[j]);
				f[a[j]] = true;
			}
		}
		while(!s.empty()){
			f[s.top()] = false;
			ans[s.top()]++;
			s.pop();
		}
	}
	for(int i = 1; i <= m; i++)	cout << ans[i] << ' ';
	return 0;
}
