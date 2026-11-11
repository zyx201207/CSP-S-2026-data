#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, ans[300005], a[500005], last[300005];
int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		last[a[i]] = i;
	} 
	for(int i = 1; i <= n; ++i){
		for(int j = i; j <= n; ++j){
			if(last[a[j]] != j){
				j = last[a[j]];
			}
			++ans[a[j]];
		}
	}
	for(int i = 1; i <= m; ++i){
		cout << ans[i] << ' ';
	}
}//ÓÐÈËÍæÖÕÄ©µØÂð 
