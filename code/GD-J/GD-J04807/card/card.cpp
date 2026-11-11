#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++) cin >> a[i];
	bool f = 1;
	vector<int> ans(m + 1), las(m + 1), cnt(m + 1);
	for(int i = 1; i <= n; i++){
		if(i > 1 && a[i] < a[i - 1]) f = 0;
		las[a[i]] = i;
		cnt[a[i]]++;
	}
	if(f){
		for(int i = 1; i <= m; i++) cout << las[i] << ' ';
		return ;
	}
	vector<int> st(n + 1);
	int top = 0;
	for(int step = 1; step <= m; step++){
		vector<bool> f(m + 1);
		top = 0;
		for(int i = las[step]; i <= n; i++){
			if(!f[a[i]]){
				st[++top] = a[i];
				f[a[i]] = 1;
			}
			else{
				while(st[top] != a[i]){
					f[st[top]] = 0;
					top--;
				}
			}
		}
		for(int i = 1; i <= top; i++) ans[st[i]] += cnt[step];
	}
	for(int i = 1; i <= m; i++) cout << ans[i] << ' ';
}

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T = 1;
	while(T--) solve();
	return 0;
}//pls 呜呜呜，多给点分呗~ 
