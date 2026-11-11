#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
ll n , m;
ll a[N];
ll cnt[N] , t[N] , vis[N];
int main(){
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;++i){
		cin >> a[i];
	}
	for(int i = 1;i <= n;++i){
		memset(cnt , 0 , sizeof(cnt));
		memset(vis , 0 , sizeof(vis));
		cnt[a[i]]++;
		for(int j = i;j <= n;++j){
			for(int k = j + 1;k <= n;++k){
				if(a[j] == a[k]){
					j = k;
					memset(cnt , 0 , sizeof(cnt));
				}
				if(!vis[a[k]]){
					vis[a[k]] = 1;
					cnt[a[k]]++;
				}
			}
		}
		for(int j = 1;j <= m;++j) t[j] += cnt[j];
	}
	for(int i = 1;i <= m;++i){
		cout << t[i] << " ";
	}
	return 0;
}
